
#include <iostream>

int main() {
    
    int saves1, goals1, shot1;
    std::cin >> saves1 >> goals1 >> shot1;
    int saves2, goals2, shot2;
    std::cin >> saves2 >> goals2 >> shot2;

    if (shot1 == 0)
        saves2 = 0;
    if (shot2 == 0)
        saves1 = 0;
    
    if (saves1 == -1 && goals2 != -1 && shot2 != -1)
        saves1 = shot2 - goals2;
    if (goals1 == -1 && shot1 != -1 && saves2 != -1)
        goals1 = shot1 - saves2;
    if (shot1 == -1 && goals1 != -1 && saves2 != -1)
        shot1 = goals1 + saves2;

    if (saves2 == -1 && goals1 != -1 && shot1 != -1)
        saves2 = shot1 - goals1;
    if (goals2 == -1 && shot2 != -1 && saves1 != -1)
        goals2 = shot2 - saves1;
    if (shot2 == -1 && goals2 != -1 && saves1 != -1)
        shot2 = goals2 + saves1;
    
    std::cout << saves1 << " " << goals1 << " " << shot1 << std::endl;
    std::cout << saves2 << " " << goals2 << " " << shot2 << std::endl;
    
}
