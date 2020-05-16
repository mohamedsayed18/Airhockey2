/*
TODO
simple ball with graphics
    * dynamic ball 
*/
#include <iostream>
#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

int main() {
    
    //Creating a world (global)
    b2Vec2 gravity(0.0f, 0.0f);     //no gravity in x or y
    b2World world(gravity);
    
    //Create dynamic body (ball)
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 0.75f);
    
    b2Body* body = world.CreateBody(&bodyDef);  //Create the body
    
    //shape
    b2CircleShape player;
    player.m_p.Set(0.0f, 0.0f); //Position with respect to centre of shape
    player.m_radius = 0.1f;
    
    //fixture
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &player;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.1f;
    fixtureDef.restitution = 1;
    
    body->CreateFixture(&fixtureDef);
    b2Vec2 p = body->GetWorldPoint(b2Vec2(0.0f, 0.0f));
    b2Vec2 f (0.0f, 2.0f);
    body->ApplyForce(f, p, true);

    //simulation
    //Let's start simulation
    float timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;
    for (int32 i = 0; i < 60; ++i)
    {
        world.Step(timeStep, velocityIterations, positionIterations);
        b2Vec2 position = body->GetPosition();
        float angle = body->GetAngle();
        printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
    }
}
