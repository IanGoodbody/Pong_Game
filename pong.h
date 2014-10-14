/*
 * pong.h
 *
 *  Created on: Oct 12, 2014
 *      Author: C2C Ian Goodbody
 */

#ifndef _PONG_H
#define _PONG_H

#define SCREEN_WIDTH 96
#define SCREEN_HEIGHT 68

#define TRUE 1
#define FALSE 0

typedef unsigned char byte; 		// The lack of this type has been bugging me for far too long

typedef struct
{
	int x;
	int y;
} vector2d_st;

typedef struct
{
	vector2d_st velocity;
	vector2d_st position;
	byte radius;
} ball_st;

vector2d_st vectInit(int x, int y);
ball_st moveBall(ball_st ping);
ball_st makeBall(byte radius, int xPos, int yPos, int xVel, int yVel);

byte topCollide(ball_st ping);
byte bottomCollide(ball_st ping);
byte leftCollide(ball_st ping);
byte rightCollide(ball_st ping);

#endif
