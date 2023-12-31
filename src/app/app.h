#ifndef APP_H
#define APP_H

#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <filesystem>
#include "../classes/user/user.h"
#include "../classes/mail/mail.h"
#include "../classes/activity/activity.h"


void MenuInicioSesion();
void MenuRegistro();
void MenuVerActividades(int user_is_registered, User generated_user); //Si el parametro es 0 no se podra preinscribirse en las actividades, si es 1 si se podra
void DetallesActividadSinRegistro(std::string nombre_fichero_actividad);
void DetallesActividadConRegistro(User generated_user, std::string nombre_fichero_actividad);
void DetallesActividadAdministracion(User generated_user, std::string nombre_fichero_actividad);
void MenuGeneral(User generated_user); //Se le pasa por parametro el usuario que ha iniciado sesion
void VerInformacionUsuario(User generated_user); //Se le pasa por parametro el usuario que ha iniciado sesion
void MenuGeneralAdmin(User generated_user); //Se le pasa por parametro el usuario que ha iniciado sesion
void VerListaCorreos(User generated_user); //Se le pasa por parametro el usuario que ha iniciado sesion
void EnviarCorreo();
void CrearActividad();

#endif