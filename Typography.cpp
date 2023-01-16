#include "Typography.h"

using namespace std;

ostream& operator<<(ostream& os, const Typography& typography)
{
	for (int i = 0; i < typography.m_books.size(); i++)
	{
		os << "�����" << endl;
		os << typography.m_books[i] << endl;
	}
				
	for (int i = 0; i < typography.m_posters.size(); i++)
	{
		os << "������" << endl;
		os << typography.m_posters[i] << endl;
	}
		
	for (int i = 0; i < typography.m_businessCards.size(); i++)
	{
		os << "�������" << endl;
		os << typography.m_businessCards[i] << endl;
	}
		
	return os;
}

istream& operator>>(istream& is, Typography& typography)
{
	
	while (!is.eof())
	{
		String string;
		is >> string;

		while (string == "")
			if (!is) 
				break;
			else		
				is >> string;
			
		if (string == "�����")
		{
			Book book;
			is >> book;
			typography.AddBook(book);
		}
		else if (string == "������")
		{
			Poster poster;
			is >> poster;
			typography.AddPoster(poster);

		}
		else if (string == "�������")
		{
			BusinessCard businessCard;
			is >> businessCard;
			typography.AddBusinessCard(businessCard);
		}
	}

	return is;
}