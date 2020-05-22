/*
TODO
//Actions: Apply impulse:(x, y)
*/
#include <iostream>
#include <box2d/box2d.h>
//#include <SFML/Graphics.hpp>

#define SCALE 100

float timeStep = 1.0f / 60.0f;
int32 velocityIterations = 6;
int32 positionIterations = 2;

//Creating a world (global)
b2Vec2 gravity(0.0f, 0.0f);     //no gravity in x or y
b2World world(gravity);
b2Body* player1;
b2Body* player2;
b2Body* player3;
b2Body* player4;
b2Body* ice_ball;
b2Body* players_list[5]; // 4 Players and 1 ball


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

void playersandball(){
    //Create dynamic body (ball)
    b2BodyDef p1;
    b2BodyDef p2;
    b2BodyDef p3;
    b2BodyDef p4;
    b2BodyDef ice_b;
    p1.type = b2_dynamicBody;
    p2.type = b2_dynamicBody;
    p3.type = b2_dynamicBody;
    p4.type = b2_dynamicBody;
    ice_b.type = b2_dynamicBody;
    p1.position.Set(5.5f, 1.5f); //player 1
    p2.position.Set(5.5f, 2.5f); //player 2
    p3.position.Set(1.5f, 1.5f); //player 3
    p4.position.Set(1.5f, 2.5f); //player 4
    ice_b.position.Set(3.5f, 2.0f);
    
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
    players_list[0] = world.CreateBody(&p1);  //Create the body
    players_list[1] = world.CreateBody(&p2);  //Create the body
    players_list[2] = world.CreateBody(&p3);  //Create the body
    players_list[3] = world.CreateBody(&p4);  //Create the body
    players_list[4]= world.CreateBody(&ice_b);  //Create the body

    // Create fixtures for the players
    for(int i=0; i<5; i++){
        players_list[i]->CreateFixture(&fixtureDef);
    }
}

void move_step(float *actions){
    /*
    actions list (8): 4x2 4 players, 2 actions each
    */
    for(int i=0; i<4; i+=2){
        b2Vec2 p = players_list[i]->GetWorldPoint(b2Vec2(0.0f, 0.0f));
        b2Vec2 f(actions[i], actions[i+1]);
        players_list[i]->ApplyLinearImpulse( f, p, false);
    }
    world.Step(timeStep, velocityIterations, positionIterations);
}

int compute_reward(){
    //check the position of the Ball 
    b2Vec2 position = players_list[4]->GetPosition();
    if(position.x<0.75){
        return 1;
    }
    else if(position.x>6.25){
        return -1;
    }
    else{
        return 0;
    }
}
