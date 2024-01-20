#include <string>
#include <unordered_map>

static int& getReg(std::unordered_map<std::string, int>& regs, std::string name)
{
  
}

std::unordered_map<std::string, int> assembler(const std::vector<std::string>& program)
{
	std::unordered_map<std::string, int> result;
	std::string key = "", secondkey = "";
	for (size_t i = 0; i < program.size(); i++) {
		key = program[i][4];
		switch (program[i][0])
		{
		case 'm':
			if ((program[i][6] > 96) & (program[i][6] < 123)) {
				secondkey = program[i][6];
				result[key] = result[secondkey];
			}
			else
				result[key] = stoi(program[i].substr(6, program[i].size() - 6));
			break;
		case 'i':
			result[key] += 1;
			break;
		case 'd':
			result[key] -= 1;
			break;
		case 'j':
				if (result.find(key)==result.end())
					i += stoi(program[i].substr(6, program[i].size() - 6)) - 1;
				else
					if(result.find(key)->second != 0)
						i += stoi(program[i].substr(6, program[i].size() - 6)) - 1;
			break;
		default:
			break;
		}
	}
	return result;
}