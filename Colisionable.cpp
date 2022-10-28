#include "Colisionable.h"


bool Colisionable::esColision (Colisionable& obj) const{
return getBounds().intersects(obj.getBounds());
}
