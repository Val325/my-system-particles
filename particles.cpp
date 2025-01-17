#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <loadshaders.hpp>
#include <camera.hpp>
#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow *window);

//FragColor = vec4(1.0, 0.0, 0.0, 1.0);


// settings
const unsigned int WINDOW_WIDTH = 800;
const unsigned int WINDOW_HEIGHT = 600;

// camera
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
float lastX = (float)WINDOW_WIDTH / 2.0;
float lastY = (float)WINDOW_HEIGHT / 2.0;
bool firstMouse = true;

// timing
float deltaTime = 0.0f;
float lastFrame = 0.0f;

int numElem = 10;
int AmountPoints = 10000 * numElem; 

float RandomFloat(float a, float b) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}


//Struct Point
struct PositionPoints{             
  int xpos;         
  int ypos;   
};
std::vector<PositionPoints> PosPoint;

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Render system particles", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    // tell GLFW to capture our mouse
    //glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    //broked
    //glEnable(GL_PROGRAM_POINT_SIZE); 
    glEnable(GL_DEPTH_TEST);
    glPointSize(4.0f);
    Shader particles("shaders/vertex.vert", "shaders/fragment.frag", "shaders/shaderparticles.geometry"); 
    /* 
    float points[] = {
	    -0.5f,  0.5f, // top-left
	    0.5f,  0.5f, // top-right
	    0.5f, -0.5f, // bottom-right
	    -0.5f, -0.5f  // bottom-left
    };*/  
    //float pointsParticles[AmountPoints] = {0.0f};
    glm::vec4 red(1.0f, 0.0f, 0.0f, 1.0f);
    glm::vec4 white(0.0f, 0.0f, 0.0f, 1.0f);
    glm::vec4 yellow(0.0f, 0.0f, 1.0f, 1.0f);
    float pointsParticles[AmountPoints];
    /*
        pointsParticles[i] = RandomFloat(-1.0, 1.0);
        pointsParticles[i+1] = RandomFloat(-1.0, 1.0);
        pointsParticles[i+2] = RandomFloat(-1.0, 1.0);
        pointsParticles[i+3] = 1.0;
        pointsParticles[i+4] = 0.0;
        pointsParticles[i+5] = 0.0;
        i++;
        i++;
     */
    const int offsetPack = 9;


    while (!glfwWindowShouldClose(window))
    {

        // per-frame time logic
        // --------------------
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);
 
        // configure transformation matrices
        glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT, 1.0f, 100.0f);
        glm::mat4 view = camera.GetViewMatrix();;
        glm::mat4 model = glm::mat4(1.0f);
                

        
        //for (int i = 0; i <= AmountPoints / numElem; ++i){

            
            

            
        //}  


    for (int i = 0; i < AmountPoints / numElem; ++i){
        pointsParticles[i] = RandomFloat(-1.0, 1.0);
        pointsParticles[i+1] = RandomFloat(0.0, 1.0);
        pointsParticles[i+2] = RandomFloat(-1.0, 1.0);
        float choiceColor = RandomFloat(0.0, 2.5);

        if (choiceColor > 0.0 && choiceColor < 1.0){
            pointsParticles[i+3] = 1.0;
            pointsParticles[i+4] = 0.0;
            pointsParticles[i+5] = 0.0;
        }
        if (choiceColor > 1.0 && choiceColor < 2.0){
            pointsParticles[i+3] = 1.0;
            pointsParticles[i+4] = 1.0;
            pointsParticles[i+5] = 0.0;
        }
        if (choiceColor > 2.0){
            pointsParticles[i+3] = 1.0;
            pointsParticles[i+4] = 1.0;
            pointsParticles[i+5] = 1.0;
        }
	    //movement
	    pointsParticles[i+6] = RandomFloat(0.0, 1.0);
	    pointsParticles[i+7] = RandomFloat(0.0, 2.5);
	    pointsParticles[i+8] = RandomFloat(0.0, 1.0);
        //size
	    pointsParticles[i+9] = RandomFloat(0.0, 2.0);
        i = i+offsetPack;
    }

        unsigned int VBO, VAO;
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(pointsParticles), pointsParticles, GL_STATIC_DRAW);
        
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, numElem * sizeof(float), (GLvoid*)0);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, numElem * sizeof(float), (GLvoid*)(3 * sizeof(float)));
        glEnableVertexAttribArray(2);
        glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, numElem * sizeof(float), (GLvoid*)(6 * sizeof(float)));
        glEnableVertexAttribArray(3);
        glVertexAttribPointer(3, 1, GL_FLOAT, GL_FALSE, numElem * sizeof(float), (GLvoid*)(9 * sizeof(float)));
        
        particles.use();	
        particles.setMat4("projection", projection);
        particles.setMat4("view", view);
        particles.setMat4("model", model);
        particles.setFloat("time", currentFrame);
        particles.setFloat("random", RandomFloat(1.0, 1.2));
        particles.setFloat("deltaTime", deltaTime);
        
        glBindVertexArray(VAO);
        glDrawArrays(GL_POINTS, 0, AmountPoints / numElem);   

        glfwSwapBuffers(window);
        glfwPollEvents();

    }

    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.ProcessKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.ProcessKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.ProcessKeyboard(RIGHT, deltaTime);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
    float xpos = static_cast<float>(xposIn);
    float ypos = static_cast<float>(yposIn);
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.ProcessMouseScroll(static_cast<float>(yoffset));
}
