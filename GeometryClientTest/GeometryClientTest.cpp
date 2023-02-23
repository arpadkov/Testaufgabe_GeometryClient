#include "pch.h"
#include "CppUnitTest.h"
#include "../Vector3D.cpp"
#include "../LineParser.cpp"
#include "../DataPoint.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GeometryClientTest
{

	TEST_CLASS(Vector3DTest)
	{
	public:
		TEST_METHOD(Vector3DEqualsTest)
		{
			Vector3D vector1 = Vector3D(1.653, 1.982, 1.333);
			Vector3D vector2 = Vector3D(1.653, 1.982, 1.333);
			Assert::IsTrue(vector1 == vector2);

			Vector3D vector3 = Vector3D(1.65300001, 1.982, 1.333);
			Vector3D vector4 = Vector3D(1.653, 1.982, 1.333);
			Assert::IsTrue(vector3 == vector4);
		}

		TEST_METHOD(Vector3DNotEqualsTest)
		{
			Vector3D vector1 = Vector3D(1.0000001, 1.0, 1.0);
			Vector3D vector2 = Vector3D(1.0, 1.0, 1.0);
			Assert::IsFalse(vector1 == vector2);
		}

		TEST_METHOD(Vector3DAdditionTest)
		{
			Vector3D originalVector1 = Vector3D(1.0, 2.0, 3.0);
			Vector3D offsetVector1 = Vector3D(1.0, 0.0, 0.0);
			Vector3D newVector1 = originalVector1 + offsetVector1;
			Vector3D verifyVector1 = Vector3D(2.0, 2.0, 3.0);
			Assert::IsTrue(newVector1 == verifyVector1);

			Vector3D originalVector2 = Vector3D(1.0, 1.0, 1.0);
			Vector3D offsetVector2 = Vector3D(-1.0, -2.0, -3.0);
			Vector3D newVector2 = originalVector2 + offsetVector2;
			Vector3D verifyVector2 = Vector3D(0.0, -1.0, -2.0);
			Assert::IsTrue(newVector2 == verifyVector2);

			Vector3D originalVector3 = Vector3D(1.0, -2.0, 3.0);
			Vector3D offsetVector3 = Vector3D(-1.0, 2.0, 3.0);
			Vector3D newVector3 = originalVector3 + offsetVector3;
			Vector3D verifyVector3 = Vector3D(0.0, 0.0, 6.0);
			Assert::IsTrue(newVector3 == verifyVector3);

			Vector3D originalVector4 = Vector3D(-1.0, -2.0, 3.0);
			Vector3D offsetVector4 = Vector3D(1.0, -2.0, -3.0);
			Vector3D newVector4 = originalVector4 + offsetVector4;
			Vector3D verifyVector4 = Vector3D(0.0, -4.0, 0.0);
			Assert::IsTrue(newVector4 == verifyVector4);
		}

		TEST_METHOD(Vector3DUnitvectorTest)
		{
			Vector3D originalVector1 = Vector3D(3.0, 0.0, 0.0);
			Vector3D verifyVector1 = Vector3D(1.0, 0.0, 0.0);
			Vector3D unitVector1 = originalVector1.getUnitVector();
			Assert::IsTrue(unitVector1 == verifyVector1);

			Vector3D originalVector2 = Vector3D(-3.0, 0.0, 0.0);
			Vector3D verifyVector2 = Vector3D(-1.0, 0.0, 0.0);
			Vector3D unitVector2 = originalVector2.getUnitVector();
			Assert::IsTrue(unitVector2 == verifyVector2);

			Vector3D originalVector3 = Vector3D(0.0, 3.0, 3.0);
			Vector3D verifyVector3 = Vector3D(0.0, 0.70710678, 0.70710678);
			Vector3D unitVector3 = originalVector3.getUnitVector();
			Assert::IsTrue(unitVector3 == verifyVector3);

			Vector3D originalVector4 = Vector3D(3.0, 3.0, -3.0);
			Vector3D verifyVector4 = Vector3D(0.57735027, 0.57735027, -0.57735027);
			Vector3D unitVector4 = originalVector4.getUnitVector();
			Assert::IsTrue(unitVector4 == verifyVector4);
		}

		TEST_METHOD(Vector3DMultiplyTest)
		{
			Vector3D originalVector1 = Vector3D(1.0, 1.0, 1.0);
			Vector3D verifyVector1 = Vector3D(2.0, 2.0, 2.0);
			double factor1 = 2.0;
			Vector3D scaledVector1 = originalVector1 * factor1;
			Assert::IsTrue(scaledVector1 == verifyVector1);

			Vector3D originalVector2 = Vector3D(-1.0, -1.0, -1.0);
			Vector3D verifyVector2 = Vector3D(-2.0, -2.0, -2.0);
			double factor2 = 2.0;
			Vector3D scaledVector2 = originalVector2 * factor2;
			Assert::IsTrue(scaledVector2 == verifyVector2);

			Vector3D originalVector3 = Vector3D(-1.0, -1.0, 1.0);
			Vector3D verifyVector3 = Vector3D(2.0, 2.0, -2.0);
			double factor3 = -2.0;
			Vector3D scaledVector3 = originalVector3 * factor3;
			Assert::IsTrue(scaledVector3 == verifyVector3);

			Vector3D originalVector4 = Vector3D(1.0, 1.0, 1.0);
			Vector3D verifyVector4 = Vector3D(0.0, 0.0, 0.0);
			double factor4 = 0.0;
			Vector3D scaledVector4 = originalVector4 * factor4;
			Assert::IsTrue(scaledVector4 == verifyVector4);
		}

	};

	TEST_CLASS(LineParserTest)
	{
	public:

		std::string dataPointLine =
			"E0000 # PtMeas(X(-711.2140549),Y(863.4),Z(400.6150898),IJK(-0.3746066,0.0,0.9271839),R(1.1679))";
		LineParser dataPointParser = LineParser(dataPointLine);

		std::string errorLine =
			"E0000 !Error(3,500,HealthCheck,\"Emergency Stop\")";
		LineParser errorParser = LineParser(errorLine);

		TEST_METHOD(findXTest)
		{
			Assert::AreEqual(dataPointParser.findXvalue(), -711.2140549);
		}

		TEST_METHOD(findYTest)
		{
			Assert::AreEqual(dataPointParser.findYvalue(), 863.4);
		}

		TEST_METHOD(findZTest)
		{
			Assert::AreEqual(dataPointParser.findZvalue(), 400.6150898);
		}

		TEST_METHOD(findNormalXTest)
		{
			Assert::AreEqual(dataPointParser.findNormalXvalue(), -0.3746066);
		}

		TEST_METHOD(findNormalYTest)
		{
			Assert::AreEqual(dataPointParser.findNormalYvalue(), 0.0);
		}

		TEST_METHOD(findNormalZTest)
		{
			Assert::AreEqual(dataPointParser.findNormalZvalue(), 0.9271839);
		}

		TEST_METHOD(findRTest)
		{
			Assert::AreEqual(dataPointParser.findRvalue(), 1.1679);
		}

		TEST_METHOD(findErrorMessageTest)
		{
			std::string errorMessage = "Emergency Stop";
			Assert::AreEqual(errorParser.findErrorMessage(), errorMessage);
		}

		TEST_METHOD(findErrorSeverityTest)
		{
			std::string errorSeverity = "3";
			Assert::AreEqual(errorParser.findErrorSeverity(), errorSeverity);
		}

		TEST_METHOD(findErrorCodeTest)
		{
			std::string errorCode = "500";
			Assert::AreEqual(errorParser.findErrorCode(), errorCode);
		}

		TEST_METHOD(findErrorMethodTest)
		{
			std::string errorMethod = "HealthCheck";
			Assert::AreEqual(errorParser.findErrorMethod(), errorMethod);
		}

	};

	TEST_CLASS(DataPointTest)
	{
	public:

		std::string inputString =
			"E0000 # PtMeas (X(100), Y(100), Z(100), IJK(5.1,6.2,7.3), R(5))";
		DataPoint dataPoint = DataPoint(inputString);

		TEST_METHOD(collisionPointCalcTest)
		{
			Vector3D normalVector = Vector3D(5.1, 6.2, 7.3);
			Vector3D measurementPoint = Vector3D(100, 100, 100);
			double sphereRadius = 5.0;

			// Tested in Geometry3DTest->Vector3DUnitvectorTest
			Vector3D unitVector = normalVector.getUnitVector();

			// Reversing unitvector, tested in Geometry3DTest->Vector3DMultiplyTest
			Vector3D unitVectorReversed = unitVector * -1;

			// Multiplying by sphere radius
			Vector3D offsetVector = unitVectorReversed * sphereRadius;

			// Offsetting point, tested in Vector3DMultiplyTest->Point3DOffsetTest			
			Vector3D verifyPoint = measurementPoint + offsetVector;

			Vector3D collisionPoint = dataPoint.getCollisionPoint();
			Assert::IsTrue(verifyPoint == collisionPoint);
		}

	};


}
