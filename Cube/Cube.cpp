#include "Cube.h"

Cube::Cube(std::string s) : m_string{s}, cubeElements{}
{
	for (size_t i = 0; i < m_size; ++i) {
		cubeElements[i] = s[i];
        }
}


void Cube::printCube() const
{
	std::cout << m_string;
}


std::string Cube::getString() const
{
        return m_string;
}


void Cube::copyElements()
{
        for (size_t i = 0; i < m_size; ++i) {
                m_string[i] = cubeElements[i];
        }
}


void Cube::rotateRight()
{
        cubeElements[0] = m_string[4];
        cubeElements[1] = m_string[0];
        cubeElements[2] = m_string[3];
        cubeElements[3] = m_string[7];
        cubeElements[4] = m_string[5];
        cubeElements[5] = m_string[1];
        cubeElements[6] = m_string[2];
        cubeElements[7] = m_string[6];

        copyElements();
}

void Cube::rotateLeft()
{
        cubeElements[0] = m_string[1];
        cubeElements[1] = m_string[5];
        cubeElements[2] = m_string[6];
        cubeElements[3] = m_string[2];
        cubeElements[4] = m_string[0];
        cubeElements[5] = m_string[4];
        cubeElements[6] = m_string[7];
        cubeElements[7] = m_string[3];

        copyElements();
}


void Cube::rotateUp()
{
        cubeElements[0] = m_string[3];
        cubeElements[1] = m_string[2];
        cubeElements[2] = m_string[6];
        cubeElements[3] = m_string[7];
        cubeElements[4] = m_string[0];
        cubeElements[5] = m_string[1];
        cubeElements[6] = m_string[5];
        cubeElements[7] = m_string[4];

        copyElements();
}

void Cube::rotateDown()
{
        cubeElements[0] = m_string[4];
        cubeElements[1] = m_string[5];
        cubeElements[2] = m_string[1];
        cubeElements[3] = m_string[0];
        cubeElements[4] = m_string[7];
        cubeElements[5] = m_string[6];
        cubeElements[6] = m_string[2];
        cubeElements[7] = m_string[3];

        copyElements();
}

