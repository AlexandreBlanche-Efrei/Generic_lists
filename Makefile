all:
	@cc							\
		src/*.c					\
		-o main					\
		-I include/				\

clean:
	@rm main