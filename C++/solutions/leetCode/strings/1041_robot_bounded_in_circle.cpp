/*
Problem: 1041
Link: https://leetcode.com/problems/robot-bounded-in-circle/
*/

/*
Solution 1 
*/
class Solution {
public:
    bool isRobotBounded(string instructions) {
        // Directions map: 0 = North, 1 = East, 2 = South, 3 = West
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        int x = 0, y = 0;
        int dir = 0;
        for(char instruction : instructions){
            if(instruction == 'G'){
                x += dx[dir];
                y += dy[dir];
            }
            else if(instruction == 'R'){
                dir = (dir+1) % 4;
            }
            else if(instruction == 'L'){
                dir = (dir+3) % 4;
            }
                
            }
            return (dir != 0 || (x == 0 && y == 0));
        }
        
};
