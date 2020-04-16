#pragma once
#include <vector>
#include <utility>

class Solution {
private:
    std::vector<std::vector<int> > bitmap;
    const char* matrix;
    int rows, cols;

    void mark(int row, int col)
    {
        bitmap[row][col] = 1;
    }
    
    void unmark(int row, int col)
    {
        bitmap[row][col] = 0;
    }

    // recursively try to match str[0]
    bool findNext(const char* str, int row, int col)
    {
        // validate input
        if (nullptr == str)
        {
            return false;
        }        
        
        // if the matrix has only 1 element
        // all pos expect (0, 0) would be considered illegal
        if (row < 0 || row >= rows
            || col < 0 || col >= cols )
        {
            return false;
        }        
        
        // check if  the current position is marked
        if (1 == bitmap[row][col])
        {
            return false;
        }

        // if matched:
        if (str[0] == matrix[row * cols + col])
        {
            // check if the str is complete
            if (str[1] == '\0')
            {
                return true;
            }

            //mark
            mark(row, col);

            // find next
            if (findNext(str + 1, row - 1, col))
            {
                return true;
            }
            if (findNext(str + 1, row + 1, col))
            {
                return true;
            }
            if (findNext(str + 1, row, col - 1))
            {
                return true;
            }
            if (findNext(str + 1, row, col + 1))
            {
               return true;
            }

            // backtrack if cannot proceed 
            unmark(row, col);
            return false;
        }
        // or return false
        else
        {
            return false;
        }        
    }

public:
    Solution():
        matrix(nullptr),
        rows(0), 
        cols(0)
    {}

    bool hasPath(const char* _matrix, int _rows, int _cols, const char* _str)
    {
        // validate input
        if (nullptr == _matrix
            || nullptr == _str
            || _rows == 0
            || _cols == 0)
        {
            return false;
        }

        // initialization
        matrix = _matrix;
        rows = _rows;
        cols = _cols;
        std::vector<int> line((size_t)cols, 0);
        for (int i = 0; i < rows; i++)
        {
            bitmap.push_back(line);
        }      
        
        // find an entry
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j != cols; j++)
            {              
                if (findNext(_str, i, j))
                {
                    return true;
                }   
            } // end of for j
        } // end of for i
        return false;        
    }
};
