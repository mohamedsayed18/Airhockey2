/*
TODO
simple ball with graphics
    * dynamic ball 
    * grapgic window

walls for the playground: polygonShape.SetAsEdge( b2Vec2(-15,0), b2Vec2(15,0) );
Let's create players
*/
#include <iostream>
#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

#define SCALE 100

//Creating a world (global)
b2Vec2 gravity(0.0f, 0.0f);     //no gravity in x or y
b2World world(gravity);
b2Body* player1;
b2Body* player2;
b2Body* player3;
b2Body* player4;

void walls(){
    //Creating walls
    b2BodyDef body1;    
    b2BodyDef body2;    
    b2BodyDef body3;    
    b2BodyDef body4;    
    body1.position.Set(3.5f, 0.25f); //playground
    body2.position.Set(6.75f, 2.0f); //playground 
    body3.position.Set(3.5f, 3.75f); //playground 
    body4.position.Set(0.25f, 2.0f); //playground  

    b2Body* wall1 = world.CreateBody(&body1);  //create the body
    b2Body* wall2 = world.CreateBody(&body2);  //create the body
    b2Body* wall3 = world.CreateBody(&body3);  //create the body
    b2Body* wall4 = world.CreateBody(&body4);  //create the body

    b2PolygonShape groundBox1;   //create the shape
    groundBox1.SetAsBox(3.5f, 0.25f);   //

    b2PolygonShape groundBox2;   //create the shape
    groundBox2.SetAsBox(0.25f, 1.5f);   //

    //fixture
    b2FixtureDef wall_fix1;
    b2FixtureDef wall_fix2;
    wall_fix1.shape = &groundBox1;
    wall_fix1.restitution = 0;
    wall_fix2.shape = &groundBox2;
    wall_fix2.restitution = 0;
    
    wall1->CreateFixture(&wall_fix1);
    wall2->CreateFixture(&wall_fix2);
    wall3->CreateFixture(&wall_fix1);
    wall4->CreateFixture(&wall_fix2);
}

void players(){
    //Create dynamic body (ball)
    b2BodyDef p1;
    b2BodyDef p2;
    b2BodyDef p3;
    b2BodyDef p4;
    p1.type = b2_dynamicBody;
    p2.type = b2_dynamicBody;
    p3.type = b2_dynamicBody;
    p4.type = b2_dynamicBody;
    p1.position.Set(5.5f, 1.5f); //player 1
    p2.position.Set(5.5f, 2.5f); //player 2
    p3.position.Set(1.5f, 1.5f); //player 3
    p4.position.Set(1.5f, 2.5f); //player 4
    
    //shape
    b2CircleShape circle;
    circle.m_p.Set(0.0f, 0.0f); //Position with respect to centre of shape
    circle.m_radius = 0.1f;     //10 pixel
    
    //fixture
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &circle;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.1f;
    fixtureDef.restitution = 0.5;
    
    //Create bodies
    player1 = world.CreateBody(&p1);  //Create the body
    player2 = world.CreateBody(&p2);  //Create the body
    player3 = world.CreateBody(&p3);  //Create the body
    player4 = world.CreateBody(&p4);  //Create the body
    
    // Create fixtures for the players
    player1->CreateFixture(&fixtureDef);
    player2->CreateFixture(&fixtureDef);
    player3->CreateFixture(&fixtureDef);
    player4->CreateFixture(&fixtureDef);
}

