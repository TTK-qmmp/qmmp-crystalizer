#include "effectcrystalizerfactory.h"
#include "crystalizerplugin.h"
#include "settingsdialog.h"

#include <QMessageBox>

const EffectProperties EffectCrystalizerFactory::properties() const
{
    EffectProperties properties;
    properties.name = tr("Crystalizer Plugin");
    properties.shortName = "crystalizer";
    properties.hasSettings = true;
    properties.hasAbout = true;
    return properties;
}

Effect *EffectCrystalizerFactory::create()
{
    return new CrystalizerPlugin();
}

void EffectCrystalizerFactory::showSettings(QWidget *parent)
{
    (new SettingsDialog(parent))->show();
}

void EffectCrystalizerFactory::showAbout(QWidget *parent)
{
     QMessageBox::about(parent, tr("About Crystalizer Effect Plugin"),
                        tr("Qmmp Crystalizer Effect Plugin") + "\n" +
                        tr("Written by: Greedysky <greedysky@163.com>"));
}

QString EffectCrystalizerFactory::translation() const
{
    return QString();
}
