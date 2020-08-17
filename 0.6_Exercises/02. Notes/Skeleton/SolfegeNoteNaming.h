#ifndef SOLFEGENOTENAMING_H
#define SOLFEGENOTENAMING_H

#include "NoteName.h"
#include <string>
struct SolfegeNoteNaming
{
  NoteName operator()(const std::string noteText) const
  {
	  if (noteText == "Do")
		  return 'C';
	  else if (noteText == "Re")
		  return 'D';
	  else if (noteText == "Mi")
		  return 'E';
	  else if (noteText == "Fa")
		  return 'F';
	  else if (noteText == "Sol")
		  return 'G';
	  else if (noteText == "La")
		  return 'A';
	  else if (noteText == "Si")
		  return 'B';
	  else
		  return '?';
  }
};
#endif // !SOLFEGENOTENAMING_H
