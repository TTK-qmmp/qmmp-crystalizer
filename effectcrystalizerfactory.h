/***************************************************************************
 * This file is part of the TTK qmmp plugin project
 * Copyright (C) 2015 - 2024 Greedysky Studio

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along
 * with this program; If not, see <http://www.gnu.org/licenses/>.
 ***************************************************************************/

#ifndef EFFECTCRYSTALIZERFACTORY_H
#define EFFECTCRYSTALIZERFACTORY_H

#include <qmmp/effectfactory.h>

/*!
 * @author Greedysky <greedysky@163.com>
 */
class EffectCrystalizerFactory : public QObject, public EffectFactory
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qmmp.qmmp.EffectFactoryInterface.1.0")
    Q_INTERFACES(EffectFactory)
public:
    virtual const EffectProperties properties() const override final;
    virtual Effect *create() override final;
    virtual void showSettings(QWidget *parent) override final;
    virtual void showAbout(QWidget *parent) override final;
    virtual QString translation() const override final;

};

#endif
