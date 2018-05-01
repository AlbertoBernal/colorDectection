#pragma once
#include "formaSimple.h"
#include "colores.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
class forma :
	public formaSimple
{
public:
	forma();
	forma(const colorBGR& inColor) : _colorBGR(inColor), _colorHSV(c_nullColorHSV){}
	forma(const colorHSV& inColor) : _colorHSV(inColor), _colorBGR(c_nullColorBGR){}
	virtual ~forma();
	//formas basicas
	enum class poligonal : unsigned char{
		NOFORM = 0, TRIANGULO, RECTANGULO, POLIGONO
	};
	virtual bool hasForm() final;
	//setters
	void setColorBGR(const colorBGR&);
	void setColorHSV(const colorHSV&);
	void setForma(const forma::poligonal);
	void setImagen(const cv::Mat&);
	//getters
	const colorBGR getColorBGR() const;
	const colorHSV getColorHSV() const;
	const forma::poligonal getForma() const;
	const cv::Mat getImagen() const;
private:
	void setImagefForm() {}
	colorBGR  _colorBGR;
	colorHSV  _colorHSV;
	poligonal _forma;
	cv::Mat   _imagen;
};

