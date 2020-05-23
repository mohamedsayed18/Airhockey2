/* TODOS
try with 4 observations for each player (pos, vel)
calculate the distance
calculate the angle

suggestions:
give the distance as x and y component (it will be more intiutive)
should we start the game(reset) with players and ball at the same position
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include "predprey.h"
#include "proj.cpp"

int cstep;      // the current step
float* cobservation;    // Pointer to the observations
float* caction;     // Pointer to the actions
int* cdone;     // Pointer to termination flag
// Pointer to world objects to be rendered
double* dobjects;   //KEEP THIS ALSO IF YOU DO NOT NEED IT
extern int nrobots;

Problem::Problem() 
{
    /*
    ON THE CONSTRUCTOR YOU CAN PUT YOUR CODE THAT CREATE THE ENVIRONMENT.
    ALSO YOU HAVE TO SPECIFY THE NUMBER OF ELEMENTS OF THE OBSERVATION AND ACTION VECTOR 
    In ninputs, noutputs THIS VARIABLE REFER TO THE OBSERVATION AND THE ACTION OF EACH PLAYER
    */

    // create the environment
    walls();
    playersandball();
    // read task parameters
    nrobots = 4; //number of robots YOU SHOULD SET THIS TO 4

    ninputs = 4;    //Observations(12):position(2), velocity(2), angle&Distance2players(2x3), ang&dis2ball(2)
    noutputs = 2;    //force (x,y)(2)
}


/*
* set the seed
*/
void Problem::seed(int s)
{
    rng->setSeed(s);
}


/*
* reset the initial condition randomly
* when seed is different from 0, reset the seed 
HERE SHOULD INITIALIZE THE POSITION OF THE PLAYERS AND OF THE DISK, 
AND THE VELOCITY OF THE DISK * ALSO HERE YOU SHOULD RESET THE STEP COUNTER step
*/
void Problem::reset()
{
    cstep = 0;
    playersandball();  //create players and set their position
    // Get observations RESET
    //SHOULD ALSO UPDATE THE OBSERVATION VECTOR
    getObs();
}




void Problem::copyObs(float *observation)
{
    cobservation = observation;
}


void Problem::copyAct(float *action)
{
    caction = action;
}


void Problem::copyDone(int *done)
{
    cdone = done;
}


void Problem::copyDobj(double*objs) //LEAVE THIS HERE EVEN IF YOU DO NOT NEED IT
{
    dobjects = objs;
}


/*
* update observation vector
* that contains the predator and prey observation state THIS
FUNCTION SHOULD UPDATE THE OBSERVATION VECTOR * THE OBSERVATION OF THE TWO PLAYERS AND OF THE TWO OPPONENTS SHOULD BE CONCATENATED SO CREATE A SINGLE OBSERVATION VECTOR *
*/
void Problem::getObs()
{
    /*
    length of the observation vector = 20 (4x5)
    */
    for(int i=0; i<5; i++)
    {
        b2Vec2 position = players_list[i]->GetPosition();
        b2Vec2 velocity = players_list[i]->GetLinearVelocity();
        cobservation[i] = position.x;
        cobservation[i+1] = position.y;
        cobservation[i+2] = velocity.x;
        cobservation[i+4] = velocity.y;
    }
}


/*
perform the action, update the state of the environment, update observations,
return the predator's reward 
* HERE YOU SHOULD MOVE THE PLAYER ON THE BASIS OF THE ACTION VECTOR (THAT CONTAINS THE ACTION OF THE FOUR ROBOTS) 
* YOU SHOULD COMPUTE THE REWARD OF THE PLAYER THAT COULD BE ALWAYS 0, 1 WHEN THE PLAYERS SCORE, -1 WHEN THE OPPONENT SCORE 
* YOU SHOULD UPDATE THE cdone VARIABLE (IL WILL BE ALWAYS 0, 1 WHEN THERE IS A SCORE) 
* FINALLY YOU SHOULD UPDATE THE STEPS COUNTER cstep 
* THIS FUNCTION RETURN THE REWARD
*/
double Problem::step()
{
    int reward = 0;
    *cdone = 0;

    move_step(caction);
    getObs();   // Update observation
    reward = compute_reward();
    if(reward != 0){
        *cdone = 1;
    }
    cstep++;
    return(reward);
}


int Problem::isDone()
{
    return *cdone;
}


void Problem::close()
{
//printf("close() not implemented\n");
}


/*
* create the list of robots and environmental objects to be rendered graphically
* HERE YOU SHOULD INCLUDE THE RENDERING OF ONE STEP
*/


void Problem::render()
{
    
   /*
    sf::CircleShape players_GUI[5];
    // The GUI 
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");    //Window
    // The ball
    sf::CircleShape ball(10.f);
    ball.setFillColor(sf::Color::Green);
    // players
    sf::CircleShape pl1(10.f);
    sf::CircleShape pl2(10.f);
    sf::CircleShape pl3(10.f);
    sf::CircleShape pl4(10.f);
    pl1.setFillColor(sf::Color::Blue);
    pl2.setFillColor(sf::Color::Blue);
    pl3.setFillColor(sf::Color::Red);
    pl4.setFillColor(sf::Color::Red);

    rectangle1.setPosition(0,0);
    rectangle2.setPosition(650, 50);
    rectangle3.setPosition(0,350);
    rectangle4.setPosition(0,50);

    players_GUI[0] = pl1;
    players_GUI[1] = pl2;
    players_GUI[2] = pl3;
    players_GUI[3] = pl4;
    players_GUI[4] = ball;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        for(int i=0; i<5; i++)
        {
            b2Vec2 position = players_list[i]->GetPosition();
            players_GUI[i].setPosition(position.x*SCALE, position.y*SCALE);
        }
        
        window.clear();
        for(int i=0; i<5; i++)
        {
           window.draw(players_GUI[i]);
        }
        window.draw(rectangle1);
        window.draw(rectangle2);
        window.draw(rectangle3);
        window.draw(rectangle4);
        window.display();
        window.close(); //todo remove window close() or keep it
        
    }
    */
}

