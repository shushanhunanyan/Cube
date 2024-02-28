#include <iostream>
#include <string>


class Cube
{
public:
        Cube(std::string s);

	void printCube() const;
	std::string getString() const;
        void rotateRight();
        void rotateLeft();
        void rotateUp();
        void rotateDown();
                              
private:
	const static size_t m_size = 8;
        char cubeElements[m_size];
	std::string m_string;

private:
	void copyElements();
};

