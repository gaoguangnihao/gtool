

class SystemProp
{
public:
	SystemProp();
	~SystemProp();

static	SystemProp* GetInstance() {
		return m_pInstance;
	}
public: 
	char* GetProp(const char *key);
    void SetProp(const char *key, char *value);

private:
	static SystemProp* m_pInstance;
};

SystemProp* SystemProp::m_pInstance = new SystemProp();