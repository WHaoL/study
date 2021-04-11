#ifndef __fig1_7_P14IntCell_h__
#define __fig1_7_P14IntCell_h__

/**
 * A class for simulating an integer memory cell.
 * fig1.7_P14IntCell.h
 */
class IntCell
{
public:
    explicit IntCell(int initialValue = 0);
    int read() const;
    void write(int x);

private:
    int storeValue;
};

#endif