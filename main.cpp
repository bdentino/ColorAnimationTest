#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtGui>
#include <QColor>
#include <QVariant>

#include <QtCore/private/qvariantanimation_p.h>

template<> Q_INLINE_TEMPLATE QColor _q_interpolate(const QColor& f, const QColor& t, qreal progress)
{
    return QColor(qBound(0,_q_interpolate(f.red(), t.red(), progress),255),
                  qBound(0,_q_interpolate(f.green(), t.green(), progress),255),
                  qBound(0,_q_interpolate(f.blue(), t.blue(), progress),255),
                  qBound(0,_q_interpolate(f.alpha(), t.alpha(), progress),255));
}

template<> Q_INLINE_TEMPLATE QQuaternion _q_interpolate(const QQuaternion &f,const QQuaternion &t, qreal progress)
{
    return QQuaternion::slerp(f, t, progress);
}

int main(int argc, char *argv[])
{
#ifdef QT_STATIC
    qRegisterAnimationInterpolator<QColor>(_q_interpolateVariant<QColor>);
    qRegisterAnimationInterpolator<QVector2D>(_q_interpolateVariant<QVector2D>);
    qRegisterAnimationInterpolator<QVector3D>(_q_interpolateVariant<QVector3D>);
    qRegisterAnimationInterpolator<QVector4D>(_q_interpolateVariant<QVector4D>);
    qRegisterAnimationInterpolator<QQuaternion>(_q_interpolateVariant<QQuaternion>);
#endif
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    return app.exec();
}
