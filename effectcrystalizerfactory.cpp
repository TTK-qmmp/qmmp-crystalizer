#include "effectcrystalizerfactory.h"
#include "crystalizerplugin.h"
#include "settingsdialog.h"

#include <QMessageBox>

#if (QMMP_VERSION_INT < 0x10700) || (0x20000 <= QMMP_VERSION_INT && QMMP_VERSION_INT < 0x20200)
const EffectProperties EffectCrystalizerFactory::properties() const
#else
EffectProperties EffectCrystalizerFactory::properties() const
#endif
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

#if (QMMP_VERSION_INT < 0x10700) || (0x20000 <= QMMP_VERSION_INT && QMMP_VERSION_INT < 0x20200)
void EffectCrystalizerFactory::showSettings(QWidget *parent)
{
    (new SettingsDialog(parent))->show();
}
#else
QDialog *EffectCrystalizerFactory::createSettings(QWidget *parent)
{
    return new SettingsDialog(parent);
}
#endif

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

#if QT_VERSION < QT_VERSION_CHECK(5,0,0)
#include <QtPlugin>
Q_EXPORT_PLUGIN2(crystalizer, EffectCrystalizerFactory)
#endif
