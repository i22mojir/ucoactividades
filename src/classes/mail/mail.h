#ifndef EMAIL_H
#define EMAIL_H

#include <iostream>
#include <string>

class Mail
{
private:
std::string title_;
std::string send_to_; //Nombre del usuario para enviar el correo o sector a enviar el correo
std::string desc_;

public:

Mail(std::string title="no_title", std::string send_to="empty", std::string desc="no_desc"){title_=title; send_to_=send_to; desc_=desc;}
std::string GetTitle(){return title_;}
std::string GetSendTo(){return send_to_;}
std::string GetDesc(){return desc_;}
void SetTitle(std::string title){title_ = title;}
void SetSendTo(std::string send_to){send_to_ = send_to;}
void SetDesc(std::string desc){desc_ = desc;}
}

#endif