/*
 * Core.h
 *
 *  Created on: 17 maj 2014
 *      Author: Patrik Gyllvin
 */

#ifndef CORE_H
#define CORE_H

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Window.h"

namespace Engine {
	class Core {
	public:
		Core();
		virtual ~Core();

		void createWindow( int w, int h, std::string text, bool fullscreen );
		void destroyWindow();
		
		void setInitFunction( void (*initFunc)() );
		void setUpdateFunction( void (*updtFunc)() );
		void setRenderFunction( void (*rndrFunc)() );

	private:
		Window* window;
		
		// TODO: Figure out delta-time thingy...
		void (*updateFunc)();
		void (*renderFunc)();
	};
}

#endif
