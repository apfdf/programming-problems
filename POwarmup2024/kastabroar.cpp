
#include <iostream>
#include <vector>
#include <array>

// Idé: Hitta först alla grupper av ihopkopplade noder, sedan de största träden i var och en av de. Använd kanterna över i grupperna för att
// koppla samman alla grupper

void dp(std::vector<bool>& bridge_map, std::vector<bool>& node_map, std::vector<std::array<int, 2>> bridges, int current, int prev) {

    node_map[current-1] = true;

    for (int i = 0; i < bridges.size(); i++) {
        if (!bridge_map[i]) {
            if (bridges[i][0] == current || bridges[i][1] == current) {
                int other = (bridges[i][0] == current) ? bridges[i][1] : bridges[i][0];
                if (other != prev) {
                    if (!node_map[other-1]) {
                        bridge_map[i] = true;
                        dp(bridge_map, node_map, bridges, other, current);
                    }
                }
            }
        }
    }

}

int main() {

    int N, M;
    std::cin >> N >> M;

    std::vector<std::array<int, 2>> bridges(M);
    for (int i = 0; i < M; i++)
        std::cin >> bridges[i][0] >> bridges[i][1];
    
    if (M < N-1) {
        std::cout << "Nej" << std::endl;
        return 0;
    }

    std::vector<bool> bridge_map(M);
    for (int i = 0; i < M; i++)
        bridge_map[i] = false;
    std::vector<bool> node_map(N);
    for (int i = 0; i < N; i++)
        node_map[i] = false;
    std::vector<int> reps = {};

    for (int i = 0; i < N; i++) {
        if (!node_map[i]) {
            reps.push_back(i+1);
            dp(bridge_map, node_map, bridges, i+1, -1);
        }
    }

    std::vector<std::array<int, 2>> spares = {};
    for (int i = 0; i < M; i++) {
        if (!bridge_map[i])
            spares.push_back(bridges[i]);
    }

    int to_move = reps.size() - 1;

    std::cout << "Ja" << std::endl;
    std::cout << to_move << std::endl;

    for (int i = 0; i < to_move; i++) {
        std::cout << spares[i][0] << " " << spares[i][1] << " " << reps[i] << " " << reps[i+1] << std::endl;
    }

    return 0;

}
