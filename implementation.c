/*
 * implementation.c
 *
 *  Created on: Oct 12, 2014
 *      Author: C16Ian.Goodbody
 */

#include <msp430.h>
#include "pong.h"


/**
 * Constructs a 2-dimensional vector struct
 * int x: the vector x value
 * int y: the vector y value
 *
 * returns: a vector struct
 */
vector2d_st vectInit(int x, int y)
{
	vector2d_st nVector;
	nVector.x = x;
	nVector.y = y;

	return nVector;
}

/**
 * Constructs a ball struct
 *
 * byte radius: the pixel radius of the ball, radius = 1 creates a 3x3 ball, radius = 2 creates a 5x5
 * int xPos: the starting x position of the ball, the x address of the center pixel
 * int yPos: the starting y position of th eball, the y address of the center pixel
 * int xVel: the x velocity component of the velocity vector
 * int yVel: the y velocity component of the velocity vector
 *
 * returns: a ball_st struct
 */
ball_st makeBall (byte radius, int xPos, int yPos, int xVel, int yVel)
{
	ball_st nBall;

	nBall.radius = radius;

	nBall.position = vectInit(xPos, yPos);
	nBall.velocity = vectInit(xVel, yVel);

	return nBall;
}

/**
 * Checks for a ball collision with the top of the screen. Assume top left corner is x = 0, y = 0
 *
 * ball_st ping: the ball struct being checked
 * return: TRUE if collision occures, FALSE if no collision occures
 */
byte topCollide(ball_st ping)
{
	if(ping.position.y <= ping.radius && ping.velocity.y < 0)
		return TRUE;
	else
		return FALSE;
}

/**
 * Checks for a ball collision with the bottom of the screen. Assume top left corner is x = 0, y = 0
 *
 * ball_st ping: the ball struct being checked
 * return: TRUE if collision occures, FALSE if no collision occures
 */
byte bottomCollide(ball_st ping)
{
	if(ping.position.y >= SCREEN_HEIGHT-ping.radius-1 && ping.velocity.y > 0)
		return TRUE;
	else
		return FALSE;
}

/**
 * Checks for a ball collision with the left of the screen. Assume top left corner is x = 0, y = 0
 *
 * ball_st ping: the ball struct being checked
 * return: TRUE if collision occures, FALSE if no collision occures
 */
byte leftCollide(ball_st ping)
{
	if(ping.position.x <= ping.radius && ping.velocity.x < 0)
		return TRUE;
	else
		return FALSE;
}

/**
 * Checks for a ball collision with the right of the screen. Assume top left corner is x = 0, y = 0
 *
 * ball_st ping: the ball struct being checked
 * return: TRUE if collision occures, FALSE if no collision occures
 */
byte rightCollide(ball_st ping)
{
	if(ping.position.x >= SCREEN_WIDTH-ping.radius-1 && ping.velocity.x > 0)
		return TRUE;
	else
		return FALSE;
}

/**
 * Creates a new ball struct  based off of ping's poroperties
 *
 * ball_st ping: The ball that is being moved
 */
ball_st moveBall(ball_st ping)
{
	if(rightCollide(ping) || leftCollide(ping))		// Change direction if a collision occures
		ping.velocity.x *= -1;
	if(topCollide(ping) || bottomCollide(ping))
		ping.velocity.y *= -1;

	ping.position.x += ping.velocity.x;		// Change the position of the ball based on the velocity
	ping.position.y += ping.velocity.y;

	return ping; 							// Can I do this with pointers please?
}

