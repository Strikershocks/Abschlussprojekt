#include "XMLHandler.hpp"
#include <iostream>


XMLHandler::XMLHandler(void)
{
}


XMLHandler::~XMLHandler(void)
{
}

std::string XMLHandler::loadPlayerName()
{
	// Name des Files
	std::ifstream file("settings.xml");
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	xml_node<> *pRoot = doc.first_node();

	// Auswahl des Child Nodes <Player>
	xml_node<> *pNode = pRoot->first_node("Player");

	// Von Child Node <Player> das Attribut Name auswählen
	xml_attribute<> *pAttr = pNode->first_attribute("Name");

	// Rückgabe Spielername
	return pAttr->value();
}


int XMLHandler::loadPlayerSkinIndex()
{
	// Name des Files
	std::ifstream file("settings.xml");
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	xml_node<> *pRoot = doc.first_node();
	// Auswahl des Child Nodes <Player>
	xml_node<> *pNode = pRoot->first_node("Player");

	// Von Child Node <Player> das Attribut SkinIndex auswählen
	xml_attribute<> *pAttr = pNode->first_attribute("SkinIndex");

	//Rückgabe von den SkinIndex
	return atoi(pAttr->value());
}

int XMLHandler::loadAliasing()
{
	// Name des Files
	std::ifstream file("settings.xml");
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	xml_node<> *pRoot = doc.first_node();
	// Auswahl des Child Nodes <Aliasing>
	xml_node<> *pNode = pRoot->first_node("Aliasing");

	// Von Child Node <Stufe> das Attribut SkinIndex auswählen
	xml_attribute<> *pAttr = pNode->first_attribute("Stufe");

	// Rückgabe Aliasing Stufe
	return atoi(pAttr->value());
}

int XMLHandler::loadWinX()
{
	// Name des Files
	std::ifstream file("settings.xml");
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	xml_node<> *pRoot = doc.first_node();
	// Auswahl des Child Nodes <Window>
	xml_node<> *pNode = pRoot->first_node("Window");

	// Von Child Node <Window> das Attribut X auswählen
	xml_attribute<> *pAttr = pNode->first_attribute("X");

	// Rückgabe von WinX
	return atoi(pAttr->value());
}

int XMLHandler::loadWinY()
{
	// Name des Files
	std::ifstream file("settings.xml");
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	xml_node<> *pRoot = doc.first_node();
	// Auswahl des Child Nodes <Window>
	xml_node<> *pNode = pRoot->first_node("Window");

	// Von Child Node <Window> das Attribut Y auswählen
	xml_attribute<> *pAttr = pNode->first_attribute("Y");

	// Rückgabe von WinY
	return atoi(pAttr->value());
}

std::string XMLHandler::loadRanking(int index, int auswahl)
{
	std::string indexName;
	switch(index)
	{
	case 1: 
		{
			indexName = "One";
			break;
		}
	case 2:
		{
			indexName = "Two";
			break;
		}
	case 3:
		{
			indexName = "Three";
			break;
		}
	case 4:
		{
			indexName = "Four";
			break;
		}
	case 5:
		{
			indexName = "Five";
			break;
		}
	case 6:
		{
			indexName = "Six";
			break;
		}
	case 7:
		{
			indexName = "Seven";
			break;
		}
	case 8:
		{
			indexName = "Eight";
			break;
		}
	case 9:
		{
			indexName = "Nine";
			break;
		}
	case 10:
		{
			indexName = "Ten";
			break;
		}
	}

	// Benötigten Variablen
	std::string Name, Time, Platz, Returntext;

	// Name des Files
	std::ifstream file("settings.xml");
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	xml_node<> *pRoot = doc.first_node();
	
	// Auswahl des Child Nodes <RankingPlace>
	xml_node<> *pNode = pRoot->first_node("RankingPlace");

	// Von Child Node <RankingPlace> das Attribut Place + index auswählen
	std::string strPlace = "Place" + indexName;
	const char *cstrPlace = strPlace.c_str();
	xml_attribute<> *pAttr = pNode->first_attribute(cstrPlace);

	// Name wird gespeichert
	Name = pAttr->value();

	// Auswahl des Child Nodes <RankingTime>
	pNode = pRoot->first_node("RankingTime");

	// Von Child Node <RankingTime> das Attribut Time + index auswählen
	std::string strTime = "Time" + indexName;
	const char *cstrTime = strTime.c_str();
	pAttr = pNode->first_attribute(cstrTime);
	
	// Zeit wird gespeichert
	Time = pAttr->value();

	if(auswahl == 0)
	{
		// Zusammenstellung des Platz Textes 
		Platz = "Platz: " + toString(index);
		Name = " Spieler: " + Name;
		Time = " Zeit: " + Time;
		Returntext = Platz + Name + Time; 

		return Returntext;
	}
	else
		return Time;
}

void XMLHandler::savePlayerName(std::string player)
{
	// Name des Files
	std::ifstream file("settings.xml");
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	xml_node<> *pRoot = doc.first_node();
	const char * c = player.c_str();
	// Auswahl des Child Nodes <Player>
	xml_node<> *pNode = pRoot->first_node("Player");

	// Von Child Node <Player> das Attribut Name auswählen
	xml_attribute<> *pAttr = pNode->first_attribute("Name");
	
	// Ändern des Attributs.
	pAttr->value(doc.allocate_string(c));
	XMLSave();
}

void XMLHandler::XMLSave()
{
	std::ofstream file_stored("settings.xml");
	file_stored << "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << std::endl;
	file_stored << doc;
	file_stored.close();
	doc.clear();
}

void XMLHandler::savePlayerSkinIndex(int index)
{
	char pbuff[1];
	_itoa_s(index, pbuff, 10);

	// Name des Files
	std::ifstream file("settings.xml");
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	xml_node<> *pRoot = doc.first_node();


	// Auswahl des Child Nodes <Player>
	xml_node<> *pNode = pRoot->first_node("Player");

	// Von Child Node <Player> das Attribut SkinIndex auswählen
	xml_attribute<> *pAttr = pNode->first_attribute("SkinIndex");
	
	// Ändern des Attributs.
	pAttr->value(doc.allocate_string(pbuff));
	XMLSave();
}

void XMLHandler::saveAliasing(int Aliasing)
{
	// Name des Files
	std::ifstream file("settings.xml");
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	char pbuff[3];
	_itoa_s(Aliasing, pbuff, 10);

	xml_node<> *pRoot = doc.first_node();

	// Auswahl des Child Nodes <Aliasing>
	xml_node<> *pNode = pRoot->first_node("Aliasing");

	// Von Child Node <Aliasing> das Attribut Stufe auswählen
	xml_attribute<> *pAttr = pNode->first_attribute("Stufe");
	
	// Ändern des Attributs.
	pAttr->value(doc.allocate_string(pbuff));
	XMLSave();
}

void XMLHandler::saveWinXY(int x, int y)
{
	// Name des Files
	std::ifstream file("settings.xml");
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	xml_node<> *pRoot = doc.first_node();
	
	char pbuffX[5];
	_itoa_s(x, pbuffX, 10);
	
	char pbuffY[5];
	_itoa_s(y, pbuffY, 10);

	// Auswahl des Child Nodes <Window>
	xml_node<> *pNode = pRoot->first_node("Window");

	// Von Child Node <Window> das Attribut X auswählen
	xml_attribute<> *pAttr = pNode->first_attribute("X");
	
	// Ändern des Attributs.
	pAttr->value(doc.allocate_string(pbuffX));

	// Von Child Node <Window> das Attribut Y auswählen
	pAttr = pNode->first_attribute("Y");

	// Ändern des Attributs.
	pAttr->value(doc.allocate_string(pbuffY));
	XMLSave();
}

std::string XMLHandler::loadSchwierigkeit()
{
	// Name des Files
	std::ifstream file("settings.xml");
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	xml_node<> *pRoot = doc.first_node();
	// Auswahl des Child Nodes <Schwierigkeit>
	xml_node<> *pNode = pRoot->first_node("Schwierigkeit");

	// Von Child Node <Schwierigkeit> das Attribut Auswahl auswählen
	xml_attribute<> *pAttr = pNode->first_attribute("Auswahl");

	// Rückgabe von int Schwierigkeit
	return pAttr->value();
}

std::string XMLHandler::loadMusic()
{
	// Name des Files
	std::ifstream file("settings.xml");
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	xml_node<> *pRoot = doc.first_node();
	// Auswahl des Child Nodes <Music>
	xml_node<> *pNode = pRoot->first_node("Music");

	// Von Child Node <Music> das Attribut An auswählen
	xml_attribute<> *pAttr = pNode->first_attribute("An");

	// Rückgabe von String an
	return pAttr->value();
}

std::string XMLHandler::loadSteuerung()
{
	// Name des Files
	std::ifstream file("settings.xml");
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	xml_node<> *pRoot = doc.first_node();
	// Auswahl des Child Nodes <Schwierigkeit>
	xml_node<> *pNode = pRoot->first_node("Steuerung");

	// Von Child Node <Schwierigkeit> das Attribut Auswahl auswählen
	xml_attribute<> *pAttr = pNode->first_attribute("Maus");

	// Rückgabe von String Maus
	return pAttr->value();
}	

int XMLHandler::loadWindowIndex()
{
	// Name des Files
	std::ifstream file("settings.xml");
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	xml_node<> *pRoot = doc.first_node();
	// Auswahl des Child Nodes <Window>
	xml_node<> *pNode = pRoot->first_node("Window");

	// Von Child Node <Window> das Attribut Index auswählen
	xml_attribute<> *pAttr = pNode->first_attribute("Index");

	// Rückgabe von int Schwierigkeit
	return atoi(pAttr->value());
}

void XMLHandler::saveWindowIndex(int index)
{
	// Name des Files
	std::ifstream file("settings.xml");
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	char pbuff[2];
	_itoa_s(index, pbuff, 10);

	xml_node<> *pRoot = doc.first_node();

	// Auswahl des Child Nodes <Window>
	xml_node<> *pNode = pRoot->first_node("Window");

	// Von Child Node <Window> das Attribut Stufe auswählen
	xml_attribute<> *pAttr = pNode->first_attribute("Index");
	
	// Ändern des Attributs.
	pAttr->value(doc.allocate_string(pbuff));
	XMLSave();
}

void XMLHandler::saveMusic(std::string An)
{
	// Name des Files
	std::ifstream file("settings.xml");
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	xml_node<> *pRoot = doc.first_node();
	const char * c = An.c_str();
	// Auswahl des Child Nodes <Music>
	xml_node<> *pNode = pRoot->first_node("Music");

	// Von Child Node <Music> das Attribut An auswählen
	xml_attribute<> *pAttr = pNode->first_attribute("An");
	
	// Ändern des Attributs.
	pAttr->value(doc.allocate_string(c));
	XMLSave();
}

void XMLHandler::saveSchwierigkeit(std::string Schwierigkeit)
{
	// Name des Files
	std::ifstream file("settings.xml");
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	const char * c = Schwierigkeit.c_str();

	xml_node<> *pRoot = doc.first_node();

	// Auswahl des Child Nodes <Schwierigkeit>
	xml_node<> *pNode = pRoot->first_node("Schwierigkeit");

	// Von Child Node <Schwierigkeit> das Attribut Stufe auswählen
	xml_attribute<> *pAttr = pNode->first_attribute("Auswahl");
	
	// Ändern des Attributs.
	pAttr->value(doc.allocate_string(c));
	XMLSave();
}

void XMLHandler::saveSteuerung(std::string Steuerung)
{
	// Name des Files
	std::ifstream file("settings.xml");
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	xml_node<> *pRoot = doc.first_node();
	const char * c = Steuerung.c_str();
	// Auswahl des Child Nodes <Steuerung>
	xml_node<> *pNode = pRoot->first_node("Steuerung");

	// Von Child Node <Music> das Attribut An auswählen
	xml_attribute<> *pAttr = pNode->first_attribute("Maus");
	
	// Ändern des Attributs.
	pAttr->value(doc.allocate_string(c));
	XMLSave();
}

void XMLHandler::saveSchwierigkeitIndex(int index)
{
	// Name des Files
	std::ifstream file("settings.xml");
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	char pbuff[2];
	_itoa_s(index, pbuff, 10);

	xml_node<> *pRoot = doc.first_node();

	// Auswahl des Child Nodes <Schwierigkeit>
	xml_node<> *pNode = pRoot->first_node("Schwierigkeit");

	// Von Child Node <Schwierigkeit> das Attribut Stufe auswählen
	xml_attribute<> *pAttr = pNode->first_attribute("Index");
	
	// Ändern des Attributs.
	pAttr->value(doc.allocate_string(pbuff));
	XMLSave();
}

int XMLHandler::loadSchwierigkeitIndex()
{
	// Name des Files
	std::ifstream file("settings.xml");
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	xml_node<> *pRoot = doc.first_node();
	// Auswahl des Child Nodes <Schwierigkeit>
	xml_node<> *pNode = pRoot->first_node("Schwierigkeit");

	// Von Child Node <Schwierigkeit> das Attribut Index auswählen
	xml_attribute<> *pAttr = pNode->first_attribute("Index");

	// Rückgabe von int Schwierigkeit Index
	return atoi(pAttr->value());
}

void XMLHandler::saveRanking(std::string Name, float Time, int index)
{
	std::string indexName;
	switch(index)
	{
	case 1: 
		{
			indexName = "One";
			break;
		}
	case 2:
		{
			indexName = "Two";
			break;
		}
	case 3:
		{
			indexName = "Three";
			break;
		}
	case 4:
		{
			indexName = "Four";
			break;
		}
	case 5:
		{
			indexName = "Five";
			break;
		}
	case 6:
		{
			indexName = "Six";
			break;
		}
	case 7:
		{
			indexName = "Seven";
			break;
		}
	case 8:
		{
			indexName = "Eight";
			break;
		}
	case 9:
		{
			indexName = "Nine";
			break;
		}
	case 10:
		{
			indexName = "Ten";
			break;
		}
	}

	// Name des Files
	std::ifstream file("settings.xml");
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	const char * cName = Name.c_str();
	char pbuff[20];
	_itoa_s(Time, pbuff, 10);

	xml_node<> *pRoot = doc.first_node();

	// Auswahl des Child Nodes <RankingPlace>
	xml_node<> *pNode = pRoot->first_node("RankingPlace");

	// Von Child Node <RankingPlace> das Attribut Place + index auswählen
	std::string strPlace = "Place" + indexName;
	const char *cstrPlace = strPlace.c_str();
	xml_attribute<> *pAttr = pNode->first_attribute(cstrPlace);
	
	// Ändern des Attributs.
	pAttr->value(doc.allocate_string(cName));
	
	// Von Child Node <RankingTime> das Attribut Time + index auswählen
	pNode = pRoot->first_node("RankingTime");
	
	// Von Child Node <Window> das Attribut Time + index auswählen
	std::string strTime = "Time" + indexName;
	const char *cstrTime = strTime.c_str();
	pAttr = pNode->first_attribute(cstrTime);

	// Ändern des Attributs.
	pAttr->value(doc.allocate_string(pbuff));
	XMLSave();
}