/*
 * File:   SyntaxMachineException.h
 * Author: Krasotsky Maxim
 */

#ifndef SYNTAXMACHINEEXCEPTION_H
#define	SYNTAXMACHINEEXCEPTION_H

#include "MachineException.h"

 // Exception for program syntax error
class SyntaxMachineException : public MachineException {
public:
    SyntaxMachineException(const std::string& msg);
    virtual ~SyntaxMachineException() throw();
private:

};

#endif	/* SYNTAXMACHINEEXCEPTION_H */
