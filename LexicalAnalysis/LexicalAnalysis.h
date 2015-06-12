#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define BUFFER_LEN 1024

enum Token
{
	VOID = 0,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,

	SHORT,
	LONG,
	SIGNED,
	UNSIGNED,

	STRUCT,
	UNION,
	ENUM,
	TYPEDEF,
	SIZEOF,

	AUTO,
	STATIC,
	REGISTER,
	EXTERN,
	CONST,
	VOLATILE,

	RETURN,
	CONTINUE,
	BREAK,
	GOTO,

	IF,
	ELSE,
	SWITCH,
	CASE,
	DEFAULT,

	FOR,
	DO,
	WHILE,

	ID,
	DECIMALNUM,
	HEXADECIMALNUM,
	LITERAL,
	PUNCTUATION,

	ERROR
};

class LexicalAnalysis
{
public:
	LexicalAnalysis(const char* _fileName);
	LexicalAnalysis(const LexicalAnalysis& _lexicalAnalysis);
	~LexicalAnalysis();

	bool Analyze();
	void Print();

private:
	// move the ptr to next point or last point, may switch the two buffers
	bool Forward();
	bool Backward();

	// the function of text processing
	bool DeleteNonsense();
	Token GetNumber(string& _string);
	Token GetKeywordOrIdentifier(string& _string);
	Token GetPunctuation(string& _string);

	// the function of judgement
	bool IsDecimalNumber(char _input);
	bool IsHexadecimalNumber(char _input);
	bool IsDot(char _input);
	bool IsAlphaOrUnderline(char _input);
	bool IsAlphaOrNumberOrUnderline(char _input);
	bool IsNonsense(char _input);
	bool IsEnd(char _input);

private:
	ifstream m_file;
	ofstream m_fout;
	int m_fileLen;
	int m_currPos;
	int m_lineNum;
	int m_wordNum;
	char m_bufferA[BUFFER_LEN];
	char m_bufferB[BUFFER_LEN];
	char* m_bufferMoved;
	bool m_isBackward;
	static const char* m_keyword[38];
	int m_keywordLen;
	static const char* m_punctuation;
	int m_punctuationLen;

	vector<pair<Token, string>> m_data;
};