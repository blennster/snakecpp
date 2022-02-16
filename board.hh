class Board
{
private:
    int size;
public:
    Board(int size);
    ~Board();
};

Board::Board(int size)
{
    this->size = size;
}

Board::~Board()
{
}
