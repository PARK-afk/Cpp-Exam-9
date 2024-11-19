#include "ShrubberyCreationForm.hpp"

// constructor

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("ShrubberyCreationForm", 145, 137), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &scf)
: AForm(scf), target(scf.target) {}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void	ShrubberyCreationForm::setTarget(std::string target)
{
	this->target = target;
}

std::string ShrubberyCreationForm::getTarget()
{
	return (this->target);
}

void	ShrubberyCreationForm::makeTree() const
{
	std::ofstream outfile((this->target + "_shrubbery").c_str());
	if (!outfile) {
		std::cerr << "open fail" << std::endl;
	}
	outfile << "          .     .  .      +     .      .          .\n";
	outfile << "     .       .      .     #       .           .\n";
	outfile << "        .      .         ###            .      .      .\n";
	outfile << "      .      .   \"#:. .:##\"##:. .:#\"  .      .\n";
	outfile << "          .      . \"####\"###\"####\"  .\n";
	outfile << "       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       .\n";
	outfile << "  .             \"#########\"#########\"        .        .\n";
	outfile << "        .    \"#:.  \"####\"###\"####\"  .:#\"   .       .\n";
	outfile << "     .     .  \"#######\"\"##\"##\"\"#######\"                  .\n";
	outfile << "                .\"##\"#####\"#####\"##\"           .      .\n";
	outfile << "    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     .\n";
	outfile << "      .     \"#######\"##\"#####\"##\"#######\"      .     .\n";
	outfile << "    .    .     \"#####\"\"#######\"\"#####\"    .      .\n";
	outfile << "            .     \"      000      \"    .     .\n";
	outfile << "       .         .   .   000     .        .       .\n";
	outfile << ".. .. ..................O000O........................ ...... ...\n";
}

void	ShrubberyCreationForm::execute(Bureaucrat &br) const
{
	if(checkExecute(br) == true)
	{
		makeTree();
	}
}

