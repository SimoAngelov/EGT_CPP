/*
 * Hall.h
 *
 *  Created on: Jun 3, 2017
 *      Author: SimoAngelov
 */

#ifndef HALL_H_
#define HALL_H_

#include <string>
using std::string;
#include <iostream>
using std::ostream;
class Hall {
private:
	int m_id;
	string m_name;
public:
	Hall(int id, const string& name);
	int getId() const;
	void setId(int id);
	const string& getName() const;
	void setName(const string& name);
	friend ostream& operator << (ostream&, const Hall&);
	virtual ~Hall();

};

#endif /* HALL_H_ */
