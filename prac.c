struct contactPerson
{
	char* contact_person_id;
	char* first_name;
	char* last_name;
	char* email;
};
struct contact
{
	char* contactid;
	char* contactname;
	char* contactstreet;
	char* area;
	char* city;
	struct contactPerson *contactPersons;
}*c;
