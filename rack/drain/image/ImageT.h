/*

MIT License

Copyright (c) 2017 FMI Open Development / Markus Peura, first.last@fmi.fi

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/
/*
Part of Rack development has been done in the BALTRAD projects part-financed
by the European Union (European Regional Development Fund and European
Neighbourhood Partnership Instrument, Baltic Sea Region Programme 2007-2013)
*/
#ifndef IMAGETEMPLATE_H_
#define IMAGETEMPLATE_H_ "Image 1.3,  2010.05.05 Markus.Peura@fmi.fi"


// TODO: rename to WritableImage ?

#include <stdlib.h>  // for exit(-1) TODO: obsolete, use std::exceptions.
#include <stdexcept>
#include <vector>
#include <ostream>

#include "util/Debug.h"
//#include "util/Options.h"

//#include "Geometry.h"
#include "Image.h"
#include "Intensity.h"
#include "Point.h"

namespace drain
{

/// General debugging // TODO: move to more general place
//static size_t Debug;

/// Namespace for images and image processing tools.
namespace image
{

//template <class T> class ImageView;

/// A class for images having using an own memory resource.
/*!
 *  Essentially, BufferedImage is a std::vector, hence a 1D structure in which
 *  further dimensions are implemented by Geometry.
 *
 *  @see BufferedView
 * 
 */
template <class T=unsigned char>
class ImageT : public Image //ImageFrame
{
public:


	ImageT(){
		setType<T>();
		//setCoordinateHandler(defaultCoordinateHandler);
	}

	ImageT(size_t width, size_t height, size_t channelCount=1, size_t alphaChannelCount=0){
		initialize<T>(width,height,channelCount,alphaChannelCount);
		//setCoordinateHandler(defaultCoordinateHandler);
	}

	// Creates a new image having the geometry of \code image. 
	ImageT(const ImageT<T> &image){
		initialize<T>(image.getWidth(),image.getHeight(),image.getImageChannelCount(),image.getAlphaChannelCount());
		setCoordinatePolicy(image.getCoordinatePolicy());
	}

	inline
	virtual ~ImageT(){};



	/// FARMED & FRAMED

	/*


	/// For sequential (in-place) computations
    virtual typename std::vector<T>::const_iterator begin() const {
		typename std::vector<T>::const_iterator it = bufferOLD->begin();
		advance(it, offset);
    	return it;
	}

    virtual typename std::vector<T>::iterator begin() {
    	typename std::vector<T>::iterator it = bufferOLD->begin();
		advance(it, offset);
    	return it;
	}

    virtual typename std::vector<T>::const_iterator end() const {
    	typename std::vector<T>::const_iterator it = bufferOLD->begin();
		advance(it, offset + geometry.getVolume());
    	return it;
	}

    virtual typename std::vector<T>::iterator end() {
    	typename std::vector<T>::iterator it = bufferOLD->begin();
		advance(it, offset + geometry.getVolume());
    	return it;
	}


	 */





	inline
	const T & at(const size_t &i) const {
		return *(const T *)&buffer[ address(i)*byteSize ];
		//(*bufferOLD)[ address(i) ];  // slow?
	}

	inline
	T & at(const size_t &i) {
		return *(T *)&buffer[ address(i)*byteSize ];
		//return (*bufferOLD)[ address(i) ];  // slow?
	}

	inline
	const T & at(const size_t &i, const size_t &j) const {
		return *(const T *)&buffer[ address(i)*byteSize ];
		//return (*bufferOLD)[ address(i,j) ];
	};

	inline
	T & at(const size_t &i, const size_t &j){
		return *(T *)&buffer[ address(i,j)*byteSize ];
		//return (*bufferOLD)[ address(i,j) ];
	};

	inline
	const T & at(const size_t &i, const size_t &j, const size_t &k) const {
		return *(const T *)&buffer[ address(i,j,k)*byteSize ];
		//return (*bufferOLD)[ address(i,j,k) ];
	};

	inline
	T & at(const size_t &i, const size_t &j, const size_t &k) {
		return *(T *)&buffer[ address(i,j,k)*byteSize ];
		//return (*bufferOLD)[ address(i,j,k) ];
	};

	inline
	const T & at(const Point2D<int> &p) const {
		return (const T *)&buffer[ address(p.x,p.y) ];
		//return (*bufferOLD)[ address(p.x,p.y) ];
	};

	inline
	T & at(const Point2D<int> &p) {
		return (T *) & buffer[ address(p.x,p.y) ];
		//return (*bufferOLD)[ address(p.x,p.y) ];
	};



};







}

}

#endif

// Drain