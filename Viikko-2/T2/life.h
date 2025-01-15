#ifndef LIFE_H
#define LIFE_H
#include <vector>


class Life {
public:
    Life(int rows = 0, int cols =0);void set_dimensions(int rows, int cols);
    void set_dimension(int rows, int cols);
    void initialize();
    void print();
    void update();
private:
    int maxrow, maxcol;
    std::vector<std::vector<int>> grid;
    int neighbor_count(int row, int col);
};

#endif