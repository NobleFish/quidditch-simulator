#include <iostream>
#include <Player.hpp>
#include <Ball.hpp>

int main() {
    // Sample usage of Player and Ball classes
    
    Player playerA("PlayerA",{0,0}, 1.0, 1.0);
    Player playerB("PlayerB",{10,10}, 1.0, 1.0);
    Ball ball({0,0});
    
    playerA.takePossession(&ball);
    playerA.moveTo({5, 3});
    playerA.passTo(playerB.getLocation());
    playerB.takePossession(&ball);
    playerA.moveTo({6,6});
    playerB.moveTo({11,11});

    std::cout << "PlayerA Position: (" << playerA.getLocation() << ")" << std::endl;
    std::cout << "PlayerB Position: (" << playerB.getLocation() << ")" << std::endl;
    std::cout << "Ball Position: (" << ball.getLocation() << ")" << std::endl;
    
    return 0;
}
