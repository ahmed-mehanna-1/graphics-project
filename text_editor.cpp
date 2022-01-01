#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int WIDTH = 500, HEIGHT= 500;
int letter_width=10; // with shift
int letter_height=20; // with shift

GLubyte space[] =
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
GLubyte CapitalLetters[][13] = {
    {0x00, 0x00, 0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0xc3, 0xc3, 0xc3, 0x66, 0x3c, 0x18},
    {0x00, 0x00, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe},
    {0x00, 0x00, 0x7e, 0xe7, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xe7, 0x7e},
    {0x00, 0x00, 0xfc, 0xce, 0xc7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc7, 0xce, 0xfc},
    {0x00, 0x00, 0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xfc, 0xc0, 0xc0, 0xc0, 0xc0, 0xff},
    {0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xfc, 0xc0, 0xc0, 0xc0, 0xff},
    {0x00, 0x00, 0x7e, 0xe7, 0xc3, 0xc3, 0xcf, 0xc0, 0xc0, 0xc0, 0xc0, 0xe7, 0x7e},
    {0x00, 0x00, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3},
    {0x00, 0x00, 0x7e, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x7e},
    {0x00, 0x00, 0x7c, 0xee, 0xc6, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06},
    {0x00, 0x00, 0xc3, 0xc6, 0xcc, 0xd8, 0xf0, 0xe0, 0xf0, 0xd8, 0xcc, 0xc6, 0xc3},
    {0x00, 0x00, 0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0},
    {0x00, 0x00, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xdb, 0xff, 0xff, 0xe7, 0xc3},
    {0x00, 0x00, 0xc7, 0xc7, 0xcf, 0xcf, 0xdf, 0xdb, 0xfb, 0xf3, 0xf3, 0xe3, 0xe3},
    {0x00, 0x00, 0x7e, 0xe7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xe7, 0x7e},
    {0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe},
    {0x00, 0x00, 0x3f, 0x6e, 0xdf, 0xdb, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x66, 0x3c},
    {0x00, 0x00, 0xc3, 0xc6, 0xcc, 0xd8, 0xf0, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe},
    {0x00, 0x00, 0x7e, 0xe7, 0x03, 0x03, 0x07, 0x7e, 0xe0, 0xc0, 0xc0, 0xe7, 0x7e},
    {0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xff},
    {0x00, 0x00, 0x7e, 0xe7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3},
    {0x00, 0x00, 0x18, 0x3c, 0x3c, 0x66, 0x66, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3},
    {0x00, 0x00, 0xc3, 0xe7, 0xff, 0xff, 0xdb, 0xdb, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3},
    {0x00, 0x00, 0xc3, 0x66, 0x66, 0x3c, 0x3c, 0x18, 0x3c, 0x3c, 0x66, 0x66, 0xc3},
    {0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3c, 0x3c, 0x66, 0x66, 0xc3},
    {0x00, 0x00, 0xff, 0xc0, 0xc0, 0x60, 0x30, 0x7e, 0x0c, 0x06, 0x03, 0x03, 0xff}
};


GLuint fontOffset;

void makeRasterFont(void){
   GLuint i, j;
   glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

   fontOffset = glGenLists (128);
   for (i = 0,j = 'A'; i < 26; i++,j++) {
      glNewList(fontOffset + j, GL_COMPILE);
      glBitmap(8, 13, 0.0, 2.0, 10.0, 0.0, CapitalLetters[i]);

      
      glEndList();
   }
   for (i = 0,j = 'a'; i < 26; i++,j++) {
      glNewList(fontOffset + j, GL_COMPILE);
      glBitmap(8, 13, 0.0, 2.0, 10.0, 0.0, CapitalLetters[i]);
      
      glEndList();
   }
   glNewList(fontOffset + ' ', GL_COMPILE);
   glBitmap(8, 13, 0.0, 2.0, 10.0, 0.0, space);
   
   glEndList();
}

void init(void){
   glShadeModel (GL_FLAT);
   makeRasterFont();
}

void printString(char *s,int start,int end){
   glPushAttrib (GL_LIST_BIT);
   glListBase(fontOffset);
   glCallLists(end-start, GL_UNSIGNED_BYTE, (GLubyte *) s+start);
   glPopAttrib ();
}


class Cursor{
   
   public:
      int line_width=0;
      int n_lines=0;

      void add_line(){
         this->n_lines++;
      }

      void set_line_width(int line_width){
         this->line_width = line_width;
      }
      void set_n_lines(int n_lines){
         this->n_lines = n_lines;
      }

      void display(){
         glLineWidth(3);
         glBegin(GL_LINE_STRIP);
            glColor3f(1, 0, 0);
            glVertex2f(25+line_width*letter_width, HEIGHT-5-(20*(n_lines-1)));
            glVertex2f(25+line_width*letter_width, HEIGHT-5-(20*(n_lines-0)));
         glEnd();
      }

};


class LettersArray
{
public:
    char array[10000];
    int letter_length = 0;

    void push(char letter){
        array[letter_length++] = letter;
    }
    void pop(){
        letter_length = max(letter_length - 1, 0);
    }
};

LettersArray lettersArray;
Cursor cursor;

class LettersPointer {
   public:
      int current_index=0;
      int line_size=0;

      int current_line_num   = 0;
      int current_line_width = 0;

      bool finished = false;


      LettersPointer(int line_size){
         this->line_size = line_size;
         
      }


      bool is_open(){
         return !this->finished;
      }
      


      // return start,end  if both are 0 then there is no new line
      pair<int,int> get_next_line(){
         this->current_line_num++;
         cursor.set_n_lines(current_line_num);
         int index = this->current_index;
         while(index < lettersArray.letter_length){
            

            if( lettersArray.array[index] == '\n' ){
               int start = this->current_index;
               this->current_index = index+1;
               this->current_line_width = index-start;
               cursor.add_line();
               cursor.set_line_width(0);
               return {start,index}; // not including the new lien

            }
            else if((index-current_index)+1 == this->line_size){
               int start = this->current_index;
               this->current_index = index;
               cursor.set_line_width(50);
               return {start,index+1};
            } 
            
            
            index++;
            
         }

         finished = true;
         cursor.set_line_width(index-this->current_index);
         return {this->current_index,index};

         
      }
};



void display(void){
 
   GLfloat white[3] = { 1.0, 1.0, 1.0 };
   int line_size = (WIDTH/letter_width)-4;
   LettersPointer pointer(line_size);

   glClear(GL_COLOR_BUFFER_BIT);
   glColor3fv(white);

  
   while(pointer.is_open()){
      pair<int,int> p = pointer.get_next_line();
      if(p.first >= p.second ){
         continue;
      }
      

      glRasterPos2i(20, HEIGHT-(20*pointer.current_line_num));
      printString(lettersArray.array,p.first,p.second);

   }
   
   cursor.display();
   glFlush ();
}

void reshape(int w, int h)
{
   WIDTH = w;
   HEIGHT = h;
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho (0.0, w, 0.0, h, -1.0, 1.0);
   glMatrixMode(GL_MODELVIEW);
}



void keyboard(unsigned char key, int x, int y)
{
       if (int(key) == 8)
    {
        lettersArray.pop();
    }
    else if (((int(key) >= 65 && int(key) <= 90) || (int(key) >= 97 && int(key) <= 122)) || key == 32)
    {
        lettersArray.push(key);
    
    }else if(key == 27){
       exit(0);
    }else if(key == 13){
      lettersArray.push('\n');
    }

    glutPostRedisplay();

}

// void motion(int x, int y)
// {
//     static GLint screeny;
//     screeny = HEIGHT - (GLint) y;
//     glRasterPos2i(x, screeny);
//     glPixelZoom(5, 2);
//     glFlush();
// }


int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(WIDTH, HEIGHT);
   glutInitWindowPosition (100, 100);
   glutCreateWindow("Text Editor");
   init();
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutDisplayFunc(display);
   // glutMotionFunc(motion);
   glutMainLoop();
   return 0;
}