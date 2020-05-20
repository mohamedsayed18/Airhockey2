/*
TODO
simple ball with graphics
    * dynamic ball 
    * grapgic window

walls for the playground: polygonShape.SetAsEdge( b2Vec2(-15,0), b2Vec2(15,0) );
Let's create players
*/
#include "proj.cpp"

int main() {
    walls();
    players();
    //Create dynamic body (ball)
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(3.5f, 2.0f);
    
    b2Body* body = world.CreateBody(&bodyDef);  //Create the body
    
    //shape
    b2CircleShape player;
    player.m_p.Set(0.0f, 0.0f); //Position with respect to centre of shape
    player.m_radius = 0.1f;     //10 pixel
    
    //fixture
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &player;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.1f;
    fixtureDef.restitution = 0.5;
    
    body->CreateFixture(&fixtureDef);
    //b2Vec2 p = body->GetWorldPoint(b2Vec2(0.0f, 0.0f));
    //b2Vec2 f (2.1f, 0.3f);
    //body->ApplyLinearImpulse( f, p, false);
    
    //simulation
    //Let's start simulation
    float timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;

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
    pl3.setFillColor(sf::Color::Blue);
    pl4.setFillColor(sf::Color::Blue);
    
    // The walls
    sf::RectangleShape rectangle1(sf::Vector2f(700.f, 50.f));
    sf::RectangleShape rectangle2(sf::Vector2f(50.f, 300.f));
    sf::RectangleShape rectangle3(sf::Vector2f(700.f, 50.f));
    sf::RectangleShape rectangle4(sf::Vector2f(50.f, 300.f));
    
    rectangle1.setPosition(0,0);
    rectangle2.setPosition(650, 50);
    rectangle3.setPosition(0,350);
    rectangle4.setPosition(0,50);
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        world.Step(timeStep, velocityIterations, positionIterations);
        //body->ApplyLinearImpulse( b2Vec2 (0.0f, 0.0f), p, true);
        b2Vec2 position = body->GetPosition();
        b2Vec2 p1_pos = player1->GetPosition();
        b2Vec2 p2_pos = player2->GetPosition();
        b2Vec2 p3_pos = player3->GetPosition();
        b2Vec2 p4_pos = player4->GetPosition();
        float angle = body->GetAngle();
        printf("%4.2f  %4.2f\n", position.x, position.y);
        
        ball.setPosition(position.x*SCALE, position.y*SCALE);
        pl1.setPosition(p1_pos.x*SCALE, p1_pos.y*SCALE);
        pl2.setPosition(p2_pos.x*SCALE, p2_pos.y*SCALE);
        pl3.setPosition(p3_pos.x*SCALE, p3_pos.y*SCALE);
        pl4.setPosition(p4_pos.x*SCALE, p4_pos.y*SCALE);
        
        window.clear();
        window.draw(ball);
        window.draw(rectangle1);
        window.draw(rectangle2);
        window.draw(rectangle3);
        window.draw(rectangle4);
        window.draw(pl1);
        window.draw(pl2);
        window.draw(pl3);
        window.draw(pl4);
        window.display();
    }
    //clean the world
    //world->DestroyBody(body);
    return 0;
}
