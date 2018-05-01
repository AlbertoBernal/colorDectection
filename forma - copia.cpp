#include "forma.h"



forma::forma()
{
}

forma::~forma()
{
}

bool forma::hasForm()
{
	return _forma != poligonal::NOFORM ? true : false;
}

void forma::setColorBGR(const colorBGR & inColor)
{
	_colorBGR = inColor;
}

void forma::setColorHSV(const colorHSV & inColor)
{
	_colorHSV = inColor;
}

void forma::setForma(const forma::poligonal laForma)
{
	_forma = laForma;
}

void forma::setImagen(const cv::Mat &  inImagen)
{
	_imagen = inImagen;
}

const colorBGR  forma::getColorBGR() const
{
	// TODO: insertar una instrucción return aquí
	return _colorBGR;
}


const colorHSV  forma::getColorHSV() const
{
	// TODO: insertar una instrucción return aquí
	return _colorHSV;
}

const forma::poligonal forma::getForma() const
{
	return forma::poligonal{ _forma };
}

const cv::Mat forma::getImagen() const
{
	return cv::Mat(_imagen);
}
