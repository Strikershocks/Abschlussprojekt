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

	// Von Child Node <Player> das Attribut Name ausw�hlen
	xml_attribute<> *pAttr = pNode->first_attribute("Name");

	// R�ckgabe Spielername
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

	// Von Child Node <Player> das Attribut SkinIndex ausw�hlen
	xml_attribute<> *pAttr = pNode->first_attribute("SkinIndex");

	//R�ckgabe von den SkinIndex
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

	// Von Child Node <Stufe> das Attribut SkinIndex ausw�hlen
	xml_attribute<> *pAttr = pNode->first_attribute("Stufe");

	// R�ckgabe Aliasing Stufe
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

	// Von Child Node <Window> das Attribut X ausw�hlen
	xml_attribute<> *pAttr = pNode->first_attribute("X");

	// R�ckgabe von WinX
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

	// Von Child Node <Window> das Attribut Y ausw�hlen
	xml_attribute<> *pAttr = pNode->first_attribute("Y");

	// R�ckgabe von WinY
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

	// Ben�tigten Variablen
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

	// Von Child Node <RankingPlace> das Attribut Place + index ausw�hlen
	std::string strPlace = "Place" + indexName;
	const char *cstrPlace = strPlace.c_str();
	xml_attribute<> *pAttr = pNode->first_attribute(cstrPlace);

	// Name wird gespeichert
	Name = pAttr->value();

	// Auswahl des Child Nodes <RankingTime>
	pNode = pRoot->first_node("RankingTime");

	// Von Child Node <RankingTime> das Attribut Time + index ausw�hlen
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

	// Von Child Node <Player> das Attribut Name ausw�hlen
	xml_attribute<> *pAttr = pNode->first_attribute("Name");
	
	// �ndern des Attributs.
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

	// Von Child Node <Player> das Attribut SkinIndex ausw�hlen
	xml_attribute<> *pAttr = pNode->first_attribute("SkinIndex");
	
	// �ndern des Attributs.
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

	// Von Child Node <Aliasing> das Attribut Stufe ausw�hlen
	xml_attribute<> *pAttr = pNode->first_attribute("Stufe");
	
	// �ndern des Attributs.
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

	// Von Child Node <Window> das Attribut X ausw�hlen
	xml_attribute<> *pAttr = pNode->first_attribute("X");
	
	// �ndern des Attributs.
	pAttr->value(doc.allocate_string(pbuffX));

	// Von Child Node <Window> das Attribut Y ausw�hlen
	pAttr = pNode->first_attribute("Y");

	// �ndern des Attributs.
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

	// Von Child Node <Schwierigkeit> das Attribut Auswahl ausw�hlen
	xml_attribute<> *pAttr = pNode->first_attribute("Auswahl");

	// R�ckgabe von int Schwierigkeit
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

	// Von Child Node <Music> das Attribut An ausw�hlen
	xml_attribute<> *pAttr = pNode->first_attribute("An");

	// R�ckgabe von String an
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

	// Von Child Node <Schwierigkeit> das Attribut Auswahl ausw�hlen
	xml_attribute<> *pAttr = pNode->first_attribute("Maus");

	// R�ckgabe von String Maus
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

	// Von Child Node <Window> das Attribut Index ausw�hlen
	xml_attribute<> *pAttr = pNode->first_attribute("Index");

	// R�ckgabe von int Schwierigkeit
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

	// Von Child Node <Window> das Attribut Stufe ausw�hlen
	xml_attribute<> *pAttr = pNode->first_attribute("Index");
	
	// �ndern des Attributs.
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

	// Von Child Node <Music> das Attribut An ausw�hlen
	xml_attribute<> *pAttr = pNode->first_attribute("An");
	
	// �ndern des Attributs.
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

	// Von Child Node <Schwierigkeit> das Attribut Stufe ausw�hlen
	xml_attribute<> *pAttr = pNode->first_attribute("Auswahl");
	
	// �ndern des Attributs.
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

	// Von Child Node <Music> das Attribut An ausw�hlen
	xml_attribute<> *pAttr = pNode->first_attribute("Maus");
	
	// �ndern des Attributs.
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

	// Von Child Node <Schwierigkeit> das Attribut Stufe ausw�hlen
	xml_attribute<> *pAttr = pNode->first_attribute("Index");
	
	// �ndern des Attributs.
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

	// Von Child Node <Schwierigkeit> das Attribut Index ausw�hlen
	xml_attribute<> *pAttr = pNode->first_attribute("Index");

	// R�ckgabe von int Schwierigkeit Index
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

	// Von Child Node <RankingPlace> das Attribut Place + index ausw�hlen
	std::string strPlace = "Place" + indexName;
	const char *cstrPlace = strPlace.c_str();
	xml_attribute<> *pAttr = pNode->first_attribute(cstrPlace);
	
	// �ndern des Attributs.
	pAttr->value(doc.allocate_string(cName));
	
	// Von Child Node <RankingTime> das Attribut Time + index ausw�hlen
	pNode = pRoot->first_node("RankingTime");
	
	// Von Child Node <Window> das Attribut Time + index ausw�hlen
	std::string strTime = "Time" + indexName;
	const char *cstrTime = strTime.c_str();
	pAttr = pNode->first_attribute(cstrTime);

	// �ndern des Attributs.
	pAttr->value(doc.allocate_string(pbuff));
	XMLSave();
}