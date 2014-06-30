#ifndef PERSON_H
#define PERSON_H

#include <QString>

class Person {
public:

    Person( const QString &firstName = "",
            const QString &lastName = "" ) :
        m_firstName( firstName ),
        m_lastName( lastName )
    {

    }

    QString firstName( ) const
    {
        return m_firstName;
    }

    QString lastName( ) const
    {
        return m_lastName;
    }

private:
    QString m_firstName;
    QString m_lastName;
};

#endif // PERSON_H
