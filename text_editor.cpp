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

// GLubyte *convert(int index){
   
//    GLubyte b[13] = {};
//    for(int i=0;i<13;i++){
      
//       b[i] = int(CapitalLetters[index][i]);
//       // cout << int(b[i]) << "   " << int(CapitalLetters[index][i])<<endl;
//       // b[i*4+0] = int(CapitalLetters[index][i]);
//       // b[i*4+1] = int(CapitalLetters[index][i]);
//       // b[i*4+2] = int(CapitalLetters[index][i]);
//       // b[i*4+3] = int(CapitalLetters[index][i]);
//    }
//    GLubyte *c = CapitalLetters[index];
//    return c;
   
// }



void makeRasterFont(void)
{
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

void init(void)
{
   glShadeModel (GL_FLAT);
   makeRasterFont();
}

void printString(char *s,int start,int end)
{
   glPushAttrib (GL_LIST_BIT);
   glListBase(fontOffset);
   glCallLists(end-start, GL_UNSIGNED_BYTE, (GLubyte *) s+start);
   glPopAttrib ();
}


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

class LettersPointer {
   public:
      int current_index=0;
      int line_size=0;
      

      LettersPointer(int line_size){
         this->line_size = line_size;
         
      }
      


      // return start,end  if both are 0 then there is no new line
      pair<int,int> get_next_point(){
         
         int index = this->current_index;
         // cout <<" outside "<< ((index-current_index) < this->line_size) << " " << (lettersArray.array[index] != '\n') << " " << (index < lettersArray.letter_length) << " " << index <<" " <<(lettersArray.letter_length)<<" "  <<endl;
         while((index-current_index) < this->line_size && lettersArray.array[index] != '\n' && index < lettersArray.letter_length){
            index++;
            
         }

         pair<int,int> out = {this->current_index,index};
         this->current_index=index;
         if(lettersArray.array[index] == '\n'){
            this->current_index++;
         }
         return out;


         
      }
};




/* Everything above this line could be in a library 
 * that defines a font.  To make it work, you've got 
 * to call makeRasterFont() before you start making 
 * calls to printString().
 */

void motion(int x, int y)
{
   cout<<x<<" "<<y<<endl;
    static GLint screeny;
    screeny = HEIGHT - (GLint) y;
    glRasterPos2i(x, screeny);
    glPixelZoom(5, 2);
    glFlush();
}

void display(void)
{
 
   GLfloat white[3] = { 1.0, 1.0, 1.0 };


   int line_size = (WIDTH/letter_width)-4;


   LettersPointer pointer(line_size);

   glClear(GL_COLOR_BUFFER_BIT);
   glColor3fv(white);

   int n_lines=1;
   while(true){
      pair<int,int> p = pointer.get_next_point();
      if(p.first == p.second ){break;}

      glRasterPos2i(20, HEIGHT-(20*n_lines));
      printString(lettersArray.array,p.first,p.second);



      n_lines++;


   }
   
   
   



   

   // glRasterPos2i(20, HEIGHT-20);
   // printString(lettersArray.array,0,min(line_size,lettersArray.letter_length));
   // if(lettersArray.letter_length > line_size){
   //    glRasterPos2i(20, HEIGHT-40);
   //    printString(lettersArray.array,line_size,min(line_size*2,lettersArray.letter_length));
   // }
   // glRasterPos2i(20, HEIGHT-40);
   // printString(var,21,37);
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

   //  }else if(int(key)==Enter){
   //     lettersArray.push(key);

    glutPostRedisplay();

}






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
   glutMotionFunc(motion);
   glutMainLoop();
   return 0;
}