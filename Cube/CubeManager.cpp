#include "CubeManager.h"


CubeManager::CubeManager() 
	: m_countOfCubes{}
	, m_string{}
	, m_key{}
       	, cubes{} {}


CubeManager::CubeManager(std::string string, std::string key)
{
	m_countOfCubes = 0;;
	m_string = string;
	m_key = key;

}


void CubeManager::setString(std::string s)
{
	m_string = s;	
	setCountOfCubes();
	cubeCreation();
}


bool CubeManager::checkKeyValidity()
{
	//ADD if string size and key appropriable
	
	for (size_t i = 0; i < m_key.size(); i += 3) {
		if (m_key[i] != 'U' 
				&& m_key[i] != 'D' 
				&& m_key[i] != 'R' 
				&& m_key[i] != 'L')
		{
			std::cerr << "not valid key.(the only options U,D,R,L)" << std::endl;
			return false;
		}
		if (m_key[i + 1] < '0' && m_key[i + 1] > '9') {
			std::cerr << "not valid key." << std::endl;
			return false;
		}
		if (i != m_key.size() - 2) {
			if (m_key[i + 2] != ':') {
				std::cerr << "not valid key." << std::endl;
				return false;
			}
		}
	}
	return true;

}


void CubeManager::decode()
{
	if (checkKeyValidity()) {
		for (size_t i = 0; i < m_key.size(); i += 3) {
			if (m_key[i] == 'U'){
				while (m_key[i + 1] != '0') {
					cubes[i / 3]. rotateDown();
					--m_key[i + 1];
				}
			} else if (m_key[i] == 'D') {
				while (m_key[i + 1] != '0') {
		                          cubes[i / 3].rotateUp();
                                        --m_key[i + 1];
                                }
			} else if (m_key[i] == 'R') {
				while (m_key[i + 1] != '0') {
                                        cubes[i / 3].rotateLeft();
                                        --m_key[i + 1];
                                }
			} else if (m_key[i] == 'L') {
				while (m_key[i / 3] != '0') {
					cubes[i / 3].rotateRight();
                                        --m_key[i + 1];
                                }
			}
		}
	}
}


void CubeManager::setKey(std::string key)
{
	m_key = key;

}


std::string CubeManager::getKey() const
{
        return m_key;
}


std::string CubeManager::getString() const
{
        return m_string;
}


void CubeManager::setCountOfCubes()
{
	size_t size = m_string.size();

        if (size % 8 == 0) {
                m_countOfCubes = size / 8;
        } else {
                m_countOfCubes = size / 8 + 1;
        }
}


void CubeManager::cubeCreation()
{
	//ADD case if inputed string size % 8 != 0
	for (size_t i = 0; i < m_countOfCubes; ++i) {
		std::string substring = m_string.substr(i * 8, 8);
                Cube tmp(substring);
                cubes.push_back(tmp);
        }

}


void CubeManager::printAll()
{	
	for (auto m : cubes) {
                m.printCube();
        }
}

