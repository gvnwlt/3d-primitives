#include <GLEW/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

int width, height;

void draw(int w, int h) {

	GLfloat angle = 45., left = -3., right = 3., bottom = -3., top = 3.; 
	GLfloat near = 0.1f, far = 1000.; 
	GLfloat fov = 45., aspectRatio = (float)w / (float)h;

	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	//glOrtho(left, right, bottom, top, near, far); 
	gluPerspective(fov, aspectRatio, near, far); 

	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity(); 
	glTranslatef(0, 0, -10); 
	glRotatef(angle, 0.4, -1., 0.4); 

	/* Cube */
	glBegin(GL_QUADS);

	/* face 1 */
	glColor3f(1, 0, 0);
	glVertex3f(1, 1, 1); // top right
	glVertex3f(-1, 1, 1); // top-left
	glVertex3f(-1, -1, 1); // bottom-left
	glVertex3f(1, -1, 1); // bottom-right

	/* face 2 */
	glColor3f(0, 1, 0);
	glVertex3f(1, 1, -1);
	glVertex3f(1, 1, 1);
	glVertex3f(1, -1, 1);
	glVertex3f(1, -1, -1);

	/* face 3 */
	glColor3f(0, 0, 1);
	glVertex3f(1, 1, 1);
	glVertex3f(1, 1, -1);
	glVertex3f(-1, 1, -1);
	glVertex3f(-1, 1, 1);

	/* face 4 */
	glColor3f(1, 1, 0);
	glVertex3f(-1, -1, -1);
	glVertex3f(-1, -1, 1);
	glVertex3f(-1, 1, 1);
	glVertex3f(-1, 1, -1);

	/* face 5 */
	glColor3f(0, 0.5, 0.4);
	glVertex3f(1, 1, -1);
	glVertex3f(-1, 1, -1);
	glVertex3f(-1, -1, -1);
	glVertex3f(1, -1, -1);

	/* face 6 */
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(1, -1, 1);
	glVertex3f(1, -1, -1);
	glVertex3f(-1, -1, -1);
	glVertex3f(-1, -1, 1);

	glEnd();
}

int main(void)
{
	/* set window size */
	width = 640;
	height = 480;

	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* Initialize GLEW */
	if (glewInit() != GLEW_OK)
		cout << "Error!" << endl;

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* call when window gets resized to basically reset the origin */
		glfwGetFramebufferSize(window, &width, &height); // this is a callback to update the window frame buffer size after resize
		glViewport(0, 0, width, height); // gets the new resized width and height and sets origin again 

										 /* Render here */
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // added | GL_DEPTH_BUFFER_BIT
		glEnable(GL_DEPTH_TEST);

		/* draw the triangles after window is rendered */
		draw(width, height);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}