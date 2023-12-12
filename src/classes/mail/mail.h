#ifndef EMAIL_H
#define EMAIL_H

#include <string>
#include <vector>

class Mail
{
private:
std::string title_;
std::string to_person_;
std::string desc_;

public:
Mail(std::string title = "empty", std::string to_person = "empty", std::string desc = "empty"){title_ = title; to_person_ = to_person; desc_ = desc;}

std::string GetTitle(){return title_;}
std::string GetToPerson(){return to_person_;}
std::string GetDesc(){return desc_;}

void SetTitle(std::string title){title_ = title;}
void SetToPerson(std::string to_person){to_person_ = to_person;}
void SetDesc(std::string desc){desc_ = desc;}
};

#endif