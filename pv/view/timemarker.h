/*
 * This file is part of the PulseView project.
 *
 * Copyright (C) 2012 Joel Holdsworth <joel@airwebreathe.org.uk>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
 */

#ifndef PULSEVIEW_PV_VIEW_MARKER_H
#define PULSEVIEW_PV_VIEW_MARKER_H

#include <QColor>
#include <QObject>
#include <QRectF>

class QPainter;
class QRect;

namespace pv {
namespace view {

class View;

class TimeMarker : public QObject
{
	Q_OBJECT

protected:
	/**
	 * Constructor.
	 * @param view A reference to the view that owns this marker.
	 * @param colour A reference to the colour of this cursor.
	 * @param time The time to set the flag to.
	 */
	TimeMarker(const View &view, const QColor &colour, double time);

	/**
	 * Copy constructor
	 */
	TimeMarker(const TimeMarker &s);

public:
	/**
	 * Gets the time of the marker.
	 */
	double time() const;

	/**
	 * Sets the time of the marker.
	 */
	void set_time(double time);

	/**
	 * Paints the marker to the viewport.
	 * @param p The painter to draw with.
	 * @param rect The rectangle of the viewport client area.
	 */
	virtual void paint(QPainter &p, const QRect &rect);

	/**
	 * Gets the marker label rectangle.
	 * @param rect The rectangle of the ruler client area.
	 * @return Returns the label rectangle.
	 */
	virtual QRectF get_label_rect(const QRect &rect) const = 0;

	/**
	 * Paints the marker's label to the ruler.
	 * @param p The painter to draw with.
	 * @param rect The rectangle of the ruler client area.
	 * @param prefix The SI prefix to paint time value with.
	 */
	virtual void paint_label(QPainter &p, const QRect &rect,
		unsigned int prefix) = 0;

signals:
	void time_changed();

protected:
	const View &_view;
	const QColor &_colour;

	double _time;

	QSizeF _text_size;
};

} // namespace view
} // namespace pv

#endif // PULSEVIEW_PV_VIEW_MARKER_H
