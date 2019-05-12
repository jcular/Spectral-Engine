namespace sp {
	class VertexData {
	public:
		VertexData(
			float const * const dataArray, int const arraySizeint, unsigned int const * const elementIndices, int const indexCount, bool const uvCoords, bool const normalCoords);
		VertexData(VertexData const & vertexData);
		VertexData(VertexData && vertexData);
		~VertexData();

	public:

		int const getStride() const;
		float const * const getDataArray() const;
		int const getDataArraySize() const;
		unsigned int const * const getIndexArray() const;
		int const getIndexCount() const;
		bool const hasUVCoords() const;
		bool const hasNormalCoords() const;

	private:
		float * const dataArray;
		int const dataArraySize;
		unsigned int * const elementIndices;
		int const indexCount;
		bool const uvCoords;
		bool const normalCoords;
	};
}
