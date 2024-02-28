#include "Cube.h"


#include <vector>

class CubeManager
{
public:
	CubeManager();
	CubeManager(std::string, std::string);

	void setString(std::string);
	void setKey(std::string);
	std::string getKey() const;
	std::string getString() const;
	void printAll();
	void cubeCreation();
	void decode();

private:
	size_t m_countOfCubes;
	std::string m_string;
	std::string m_key;
	std::vector<Cube> cubes;

private:
	void setCountOfCubes();
	bool checkKeyValidity();
};
