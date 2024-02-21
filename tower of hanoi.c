#include <stdio.h>

// Function to perform the move
void move(int n, int source, int destination, int intermediate) {
    if (n == 1) {
        printf("Move disk from rod %d to rod %d\n", source, destination);
        return;
    }
    move(n - 1, source, intermediate, destination);
    printf("Move disk from rod %d to rod %d\n", source, destination);
    move(n - 1, intermediate, destination, source);
}

int main() {
    int num_disks = 4; // Number of disks
    int source = 1; // Source rod
    int destination = 3; // Destination rod
    int intermediate = 2; // Intermediate rod

    move(num_disks, source, destination, intermediate); // Calling the move function
    return 0;
}
