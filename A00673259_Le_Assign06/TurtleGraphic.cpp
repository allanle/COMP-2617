#include "./turtlegraphics.h"
#include <iostream>
using namespace std;

TurtleGraphics::TurtleGraphics(void) {
	for(auto & rows : m_Floor) {
		for(auto & element : rows) {
			element = false;
		}
	}
	m_Dir = STARTING_DIRECTION;
	
	m_Row = STARTING_ROW;
	m_Col = STARTING_COL;
	
	m_Pen = STARTING_PEN_POSITION;
}

void TurtleGraphics::processTurtleMoves(const array<int, ARRAY_SIZE> cmds) {
	int cmdNo = 0;
	
	bool exitFlag = false;
	
	do {
		switch(static_cast<Cmds>(cmds[cmdNo])) {
			case Cmds::PEN_UP:
				m_Pen = false;
				break;
				
			case Cmds::PEN_DWN:
				m_Pen = true;
				break;
				
			case Cmds::TURN_RIGHT:
				m_Dir += 3;
				if(m_Dir == 15) {
					m_Dir = 3;
				}
				break;
				
			case Cmds::TURN_LEFT:
				m_Dir -= 3;
				if(m_Dir == 0) {
					m_Dir = 12;
				}
				break;
				
			case Cmds::MOVE:
				++cmdNo;
				moveTurtle(cmds[cmdNo]);
				break;
			
			case Cmds::DISPLAY:
				displayFloor();
				break;
				
			case Cmds::END_OF_DATA:
				exitFlag = true;
				break;
				
			default:
				cerr << "\n\nError - invalid command encountered in processTurtleMoves() switch statement.\n\n";
				return;
		}
		++cmdNo;
	} while(!exitFlag);
}

void TurtleGraphics::moveTurtle(const int & numOfMoves) {
	if(numOfMoves < 1) {
		return;
	}
	
	int actualNumMoves = numOfMoves;
	
	switch(m_Dir) {
		case 3:
			if((numOfMoves + m_Col) > (NCOLS - 1)) {
				actualNumMoves = (NCOLS - 1) - m_Col;
			}
			
			if(m_Pen) {
				for(int i = 1; i <= actualNumMoves; ++m_Col, ++i) {
					m_Floor[m_Row][m_Col] = true;
				}
			} else {
				m_Col += actualNumMoves;
			}
			break;
			
		case 6:
			if((numOfMoves + m_Row) > (NROWS - 1)) {
				actualNumMoves = (NROWS - 1) - m_Row;
			}
			
			if(m_Pen) {
				for(int i = 1; i <= actualNumMoves; ++m_Row, ++i) {
					m_Floor[m_Row][m_Col] = true;
				}
			} else {
				m_Row += actualNumMoves;
			}
			break;
			
		case 9:
			if((m_Col - numOfMoves) < 0) {
				actualNumMoves = m_Col;
			}
			
			if(m_Pen) {
				for(int i = 1; i <= actualNumMoves; --m_Col, ++i) {
					m_Floor[m_Row][m_Col] = true;
				}
			} else {
				m_Col -= actualNumMoves;
			}
			break;
			
		case 12:
			if((m_Row - numOfMoves) < 0) {
				actualNumMoves = m_Row;
			}
			
			if(m_Pen) {
				for(int i = 1; i <= actualNumMoves; --m_Row, ++i) {
					m_Floor[m_Row][m_Col] = true;
				}
			} else {
				m_Row -= actualNumMoves;
			}
			break;
			
		default:
			cerr << "\n\nErrow - invalid direction in moveTurtle() switch statement.\n\n";
			return;
	}
}

void TurtleGraphics::displayFloor() const {
	for(auto const & rows : m_Floor) {
		for(auto const & element : rows) {
			if(element) {
				cout << '*';
			} else {
				cout << ' ';
			}
		}
		cout << endl;
	}
	cout << endl << endl;
}