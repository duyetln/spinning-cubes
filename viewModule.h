//Duyet Nguyen - 65306944 - nguyendl@uci.edu
//This file is supplied by the TA and contains no change


/*
 * OpenGL demonstration program for ICS Computer Graphics courses
 * $Id: viewModule.h,v 1.1 2002/04/03 00:00:51 mshafae Exp $
 *
 */

#ifndef  __STEREOMODULE_H
#define  __STEREOMODULE_H

#ifdef __cplusplus
extern "C" {
#endif

#define IMAGE_WIDTH  750
#define IMAGE_HEIGHT 750

typedef struct{
        float fieldOfView;
        float aspect;
        float nearPlane;
        float farPlane;
}perspectiveData;


#ifdef __cplusplus
}
#endif

#endif
