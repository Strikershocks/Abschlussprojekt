#pragma once
#include "rapidxml.hpp"
#include "rapidxml_print.hpp"
#include "rapidxml_iterators.hpp"
#include "rapidxml_utils.hpp"
#include "Include\StringHelpers.hpp"

using namespace rapidxml;

class XMLHandler
{
public:
	XMLHandler(void);
	~XMLHandler(void);

	// XML Getter
	std::string loadPlayerName();
	int loadPlayerSkinIndex();
	int loadWinX();
	int loadWinY();
	int loadAliasing();
	std::string loadMusic();
	std::string loadSchwierigkeit();
	std::string loadSteuerung();
	int loadWindowIndex();
	int loadSchwierigkeitIndex();

	std::string loadRanking(int index);

	// XML Setter
	void savePlayerName(std::string Name);
	void savePlayerSkinIndex(int index);
	void saveWinXY(int x, int y);
	void saveAliasing(int Stufe);
	void saveRanking(std::string name, std::string Time, int index);
	void saveSchwierigkeit(std::string Schwierigkeit);
	void saveMusic(std::string An);
	void saveSteuerung(std::string Steuerung);
	void saveWindowIndex(int index);
	void saveSchwierigkeitIndex(int index);

	// Speichern des Dokuments
	void XMLSave();

private:
	xml_document<> doc;
};

