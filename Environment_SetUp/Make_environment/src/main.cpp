/*
 * Based on work by Graham Sellers and OpenGL SuperBible7
 * 
 * Example first program
 * 
 */

#include <sb7.h>
#include <math.h>

class first_app : public sb7::application{      //taking the base application class and inherit it 

    public:
    /*
    //Part 1! Color!
        //function render will draw on the screen, it 
        void render(double curTime){        
            const GLfloat clr[] = { static_cast<float>(sin(curTime)) * 0.5f + 0.5f ,
                                    static_cast<float>(cos(curTime)) * 0.5f + 0.5f ,
                                     0.0f, 1.0f};

            glClearBufferfv(GL_COLOR,0,clr); //this clears the "GL_COLOR" (the color of it currently) and changes it to the clor in "clr"
        }
    //*/

//Part 2 Points!

    GLuint compile_shaders(void){
        GLuint vertex_shader;
        GLuint fragment_shader;
        GLuint program;

        
       /* static const GLchar* vertex_shader_source[] = { //this makes our vertex shader,
            "#version 450 core                           \n"    //using version  4.5 of shading language
            "                                            \n"
            "void main(void) {                           \n"    //starts the "main" to be executed 
            "    gl_Position = vec4(0.0, 0.0, 0.5, 1.0); \n" //put the vertex right in the middle fo the screen
            "}                                           \n"
        }; */
        

        // Part 3 - Triangles
        
            static const GLchar* vertex_shader_source[] = {
            "#version 450 core                                                    \n"
            "                                                                     \n"
            "void main(void) {                                                    \n"
            "    const vec4 vertices[3] = vec4[3]( vec4( 0.25, -0.25, 0.5, 1.0),  \n"
            "                                      vec4(-0.25, -0.25, 0.5, 1.0),  \n"
            "                                      vec4( 0.25,  0.25, 0.5, 1.0)); \n"
            "                                                                     \n"
            "    gl_Position = vertices[gl_VertexID];                             \n"
            "}                                                                    \n"
            };


        static const GLchar* fragment_shader_source[] = {   //makes the fragemnt shader, needed to be used vertex shader
            "#version 450 core                           \n"
            "                                            \n"
            "out vec4 color;                             \n"       //output variable
            "                                            \n"       //output variables will be sent with fragment shaders
            "void main(void) {                           \n"    
            "    color = vec4(1.0, 0.0, 0.0, 1.0);       \n"       //sets the color 
            "}                                           \n"
        };
        /*    //adding a second shader, second triangle
            static const GLchar* vertex_shader_source_[] = {
            "#version 450 core                                                    \n"
            "                                                                     \n"
            "void main(void) {                                                    \n"
            "    const vec4 vertices2[3] = vec4[3]( vec4( 0.6, 0.5, 0.5, 1.0),  \n"
            "                                      vec4(0.5, 0.6, 0.5, 1.0),  \n"
            "                                      vec4( 0.55, 0.55, 0.5, 1.0)); \n"
            "                                                                     \n"
            "    gl_Position = vertices2   [gl_VertexID];                            \n"
            "}                                                                    \n"
            };
            

        static const GLchar* fragment_shader_source_[] = {   //makes the fragemnt shader, needed with vertex shader
            "#version 450 core                           \n"
            "                                            \n"
            "out vec4 color;                             \n"    //makes an output variable
            "                                            \n"       //output varibales will be sent to screen in fragment shaders
            "void main(void) {                           \n"    
            "    color = vec4(0.0, 1.0, 0.0, 1.0);       \n"       //sets the color variabl's 
            "}                                           \n"
        }; */

        //attach the first triangle
        //Create and compile vertex shaders
        vertex_shader = glCreateShader(GL_VERTEX_SHADER); //this creates an empty shader object 
        glShaderSource(vertex_shader, 1, vertex_shader_source, NULL); //passes vertex shaders to source 
        glCompileShader(vertex_shader); //compiles shaders 

        //Create and compile fragment shader
        fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);   //creates shader object for our fragment shader
        glShaderSource(fragment_shader,1,fragment_shader_source,NULL); //passes vertex shaders to source 
        glCompileShader(fragment_shader);

        program = glCreateProgram();        //make a program to use shaders
        glAttachShader(program, vertex_shader); //sends and uses shaders to the program
        glAttachShader(program,fragment_shader);    
        glLinkProgram(program);             //links shaders together

        glDeleteShader(vertex_shader); //deletes the shaders once moved 
        glDeleteShader(fragment_shader);
        
        
        /* //attach the shaders for the second triangle 
        vertex_shader = glCreateShader(GL_VERTEX_SHADER); //this creates an empty shader object for the vertex shader we made 
        glShaderSource(vertex_shader, 1, vertex_shader_source_, NULL); //passes our created vertex shaders to source 
        glCompileShader(vertex_shader); //compiles the shader

        //Create and compile fragment shader
        fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);   //creates a shader object for our frag shader
        glShaderSource(fragment_shader,1,fragment_shader_source_,NULL); //passes our created vertex shaders to source 
        glCompileShader(fragment_shader);   //compiles the shader

        program = glCreateProgram();        //make a program to use teh shaders
        glAttachShader(program, vertex_shader); //attaches the shaders we made to the program
        glAttachShader(program,fragment_shader);    
        glLinkProgram(program);             //links the added shaders together

        glDeleteShader(vertex_shader); //deletes the shaders once they've already been copied in 
        glDeleteShader(fragment_shader); */

        return program;
    }

    void startup(){
        rendering_program = compile_shaders();  //sb7 has a function 
        glCreateVertexArrays(1, &vertex_array_object); //a vertex array object is needed to draw. Takes (GLsize size, GLuint * array) 
        glBindVertexArray(vertex_array_object);         //put the vertex array object (VAO) in place. Takes (GLunit array)
    }

    void shutdown(){
        glDeleteVertexArrays(1,&vertex_array_object);   //deletes the VAO after done
        glDeleteProgram(rendering_program);     //deletes the program after its done
        glDeleteVertexArrays(1,&vertex_array_object);
    }

    void render(double curTime){    //used to render the screen
        const GLfloat clr[] = { static_cast<float>(sin(curTime)) * 0.5f + 0.5f ,    //sets the GLfloat clr array to random #'s betwteen 0 and 1
                                static_cast<float>(cos(curTime)) * 0.5f + 0.5f ,
                                    0.0f, 1.0f};
        glClearBufferfv(GL_COLOR,0,clr);        //clears the GL_color/what's used to set the background

        glUseProgram(rendering_program);    //tells openGL to use our program that we made

        // Part 2
        //glPointSize(40.0f); //sets the diamater of the point in the pixels
        //glDrawArrays(GL_POINTS, 0, 1); // tells openGL what kind of graphics primitive we want to render, in this case GL_POINTS,
                                        // the second parameter is is not important here, and third is number of vertexs (1)
        

        //Part 3
        glDrawArrays(GL_TRIANGLES,0,3); //this tells OpenGL to draw the tiangle
    }

    private:
        GLuint rendering_program;
        GLuint vertex_array_object;

        

};


DECLARE_MAIN(first_app);
